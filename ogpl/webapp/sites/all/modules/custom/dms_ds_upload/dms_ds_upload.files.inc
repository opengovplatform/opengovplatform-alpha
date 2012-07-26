<?php

/**
 * @file
 * Part of module to deal with file parsing and assembling.
 */

/**
 * Convert the csv file to key=>value array(s).
 */
function dms_ds_upload_parse_file($filename = '') {
  $ret = array();

  $filetype = strtolower(substr(strrchr($filename,'.'),1)); //csv, xml, xls, or xlsx?

  switch ($filetype) {

    case 'csv':
      $ret = dms_ds_upload_parse_file_csv($filename);
      break;

    case 'xml':
      $ret = dms_ds_upload_parse_file_xml($filename);
      break;

    case 'xls':
    case 'xlsx':
      $ret = dms_ds_upload_parse_file_xls($filename);
      break;

  }

  return $ret;
}

function dms_ds_upload_parse_file_csv($filename = '') {
  $ret = array();
  if (($handle = fopen($filename, "r")) === FALSE) {
    return $ret;
  }

  $keys = array();
  $values = array();

  //first row is the keys
  $keys = fgetcsv($handle, 0, ",");

  //2nd row and beyond
  while (($values = fgetcsv($handle, 0, ",")) !== FALSE) {

    //skip all empty record
    $has_some_record = FALSE;
    for ($i = 0; $i < count($values); $i++) {
      $value = $values[$i];
      if (!is_null($value) && $value!=='') {
        $has_some_record = TRUE;
      }
      $values[$i] = str_getcsv($value);
    }
    if ($has_some_record) {
      $ret[] = array_combine($keys, $values);
    }
  }

  fclose($handle);
  return $ret;
}

function dms_ds_upload_parse_file_xml($filename = '') {
  //an easy way if we know xml has a flat structure.
  $xml = simplexml_load_file($filename);
  $json = json_encode($xml);
  $array = json_decode($json,TRUE);

  $record_array = NULL;
  $ret_array = array();

  if (is_null($array['dataset'][0])) {
    $record_array = array($array['dataset']);
  }
  else {
    $record_array = $array['dataset'];
  }

  //walk thru the $record_array to make it into $ret_array
  for ($i = 0; $i < count($record_array); $i++) {
    foreach ($record_array[$i] as $key => $value) {
      if (!is_array($value)) {
        $ret_array[$i][$key] = array($value);
      }
      elseif (count($value) == 0) {
        //convert empty array into array with one null element.
        $ret_array[$i][$key] = array(NULL);
      }
      else {
        //multiple value field
        $ret_array[$i][$key] = $value[$GLOBALS['dms_ds_upload_delimiter']['xml']['tag']];
      }
    }
  }
  return $ret_array;
}

function dms_ds_upload_parse_file_xls($filename = '') {
  $ret = array();
  $keys = array();
  $values = array();

  $filetype = strtolower(substr(strrchr($filename,'.'),1));
  $which_class = $filetype=='xlsx'?'Excel2007':'Excel5';

  require_once 'Classes/PHPExcel/IOFactory.php';

  $objReader = PHPExcel_IOFactory::createReader($which_class);
  $objPHPExcel = $objReader->load($filename);

  foreach ($objPHPExcel->getWorksheetIterator() as $worksheet) {

    foreach ($worksheet->getRowIterator() as $row) {
      $row_number = $row->getRowIndex();
      //first row is $key, 2nd row is decription, 3rd and beyond are data.
      if ($row_number == 2) {
        continue;
      }

      $values = array(); //empty for a new set.

      $cellIterator = $row->getCellIterator();
      //Loop all cells, even if it is not set
      $cellIterator->setIterateOnlyExistingCells(false);

      foreach ($cellIterator as $cell) {
        $column_number = $cell->getColumn();
        if ($column_number == 'A') { //description data
          continue;
        }
        $data = $cell->getCalculatedValue();
        if ($row_number == 1){
          $keys[] = $data;
        }
        else {
          if ($data == "FOR PMO USE ONLY") {
            $data = NULL;
          }
          $values[] = $data;
        }
      }
      //skip all empty record
      $has_some_record = FALSE;
      for ($i = 0; $i < count($values); $i++) {
        $value = $values[$i];
        if (!is_null($value) && $value!=='') {
          $has_some_record = TRUE;
        }
        $values[$i] = str_getcsv($value);
      }

      //first row is $key, 2nd row is decription, 3rd and beyond are data.
      if ($has_some_record && $row_number >= 3){
        $ret[] = array_combine($keys, $values);
      }

    }

    //only first worksheet supported.
    break;
  }
  return $ret;
}


/**
 * Assemble data and tell browser to download the attachment.
 */
function dms_ds_upload_download_template($format = '') {
  require_once 'dms_ds_upload.fields.inc';

  //get a list of dataset fields in the right order.
  $ordered_list = dms_ds_upload_get_sequenced_fields('dataset', $GLOBALS['dms_ds_upload_exclude_group']);
  //integrate child nodes into it.
  $ready_list = dms_ds_upload_display_sequenced_fields($ordered_list);

  $filename = 'dataset.template.' . $format;
  switch ($format) {

    case 'csv':
      header("Cache-Control: no-store, no-cache");
      header("Content-Disposition: attachment; filename=$filename");
      header("Content-type: text/csv");
      $outstream = fopen("php://output",'w');
      fputcsv($outstream, $ready_list['fieldname'], ',', '"');
      fclose($outstream);
      break;

    case 'xml':
      //create empty array as values
      $value_array = array_fill(0, count($ready_list['fieldname']), NULL);
      $assoc_array = array_combine($ready_list['fieldname'], $value_array);
      $xml_string = '  <dataset>' . PHP_EOL . assocToXML($assoc_array, 2) . '  </dataset>';
      $xml_string = '<?xml version="1.0" encoding="UTF-8"?><datasets>' . PHP_EOL . $xml_string .  PHP_EOL .'</datasets>';
      $xml = new SimpleXMLElement($xml_string);
      header('Content-type: "text/xml"; charset="utf8"');
      header('Content-disposition: attachment; filename="' . $filename . '"');
      echo $xml->asXML();
      break;

    case 'xls':
      //first we get a hash value of the fieldlist, and use it as part of the
      //filename, so that we dont repeatly creating same template file.
      $list_hash = md5(serialize($ready_list));

      //do we already have the xls file if same version?
      $template_path = file_directory_path() . '/dms_templates';
      $file_to_be = $template_path . '/dataset.template.' . $list_hash . '.xls';

      //if not yet, let us create the file.
      if (!file_exists($file_to_be)) {
        //create dir first
        if (!file_exists($template_path)) {
          mkdir ($template_path);
        }
        //use styled blank xls file as starting point. 
        $empty_template = dirname(__FILE__) . '/templates/empty.template.xls';
        if (!file_exists($empty_template)){
          drupal_set_message(t("File error. Empty template file could not be loaded."));
          drupal_goto('dataset/template');
        }
        require_once 'Classes/PHPExcel/IOFactory.php';
        $objReader = PHPExcel_IOFactory::createReader('Excel5');
        $objPHPExcel = $objReader->load($empty_template);
        $objPHPExcel->setActiveSheetIndex(0);

        //data column starts with 'B'
        $column = 'B';
        for ($i = 0; $i < count($ready_list['fieldname']); $i++) {
          $objPHPExcel->getActiveSheet()->setCellValue($column . '1', $ready_list['fieldname'][$i]);
          $objPHPExcel->getActiveSheet()->setCellValue($column . '2', $ready_list['fieldlabel'][$i]);
          $objPHPExcel->getActiveSheet()->getColumnDimension($column)->setAutoSize(true);
          //add special text for special column
          if ($ready_list['fieldname'][$i] == 'ds_unique_id') {
            for ($j = 3; $j <= 28; $j++) {
              $objPHPExcel->getActiveSheet()->setCellValue($column . $j, 'FOR PMO USE ONLY');
              $objPHPExcel->getActiveSheet()->getStyle($column . $j)->getFont()->setSize(8);
            }
          }
          $column++; //PHP's Perls-style ability to increment characters.
        }
        $objPHPExcel->getActiveSheet()->setSelectedCell('B3');
        $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
        $objWriter->save($file_to_be);

      }
      if (@ $handle = fopen ($file_to_be, "r")) {

        $file_size = filesize($file_to_be);
        header("Cache-Control: no-store, no-cache");
        header("Content-Disposition: attachment; filename=$filename");
        header("Content-type: application/vnd.ms-excel");
        header("Content-length: $file_size");
        while(!feof($handle)) {
          $buffer = fread($handle, 2048);
          echo $buffer;
        }
        fclose ($handle);
      }
      else {
        drupal_set_message(t("File error. Template file could not be created."));
        drupal_goto('dataset/template');
      }
      break;

    default:
      drupal_not_found();

  }

  exit;
}

/**
 * Retrieve data from node and assemble it into csv to download.
 */
function dms_ds_upload_download_nodes($node_ids = array(), $format = 'csv') {
  //if it is a single node id, convert it into a one element array.
  if (is_numeric($node_ids)) {
    $is_single_node = TRUE;
    $node_ids = array($node_ids);
  }

  //filename to show user when downloading.
  $filename = "datasets." . date('Y-m-d') . "." . $format;

  require_once 'dms_ds_upload.fields.inc';
  //get a list of dataset fields in the right order.
  $ordered_list = dms_ds_upload_get_sequenced_fields('dataset', $GLOBALS['dms_ds_upload_exclude_group']);
  //integrate child nodes into it.
  $ready_list = dms_ds_upload_display_sequenced_fields($ordered_list);

  require_once 'dms_ds_upload.nodes.inc';
  $all_fields = dms_ds_upload_get_fields('dataset');

  $data_list = array();
  foreach ($node_ids as $nid) {
    $node = node_load($nid);
    if (empty($node->nid)) {
      drupal_not_found();
      return;
    }

    //if single node id, give a more meaningful unique name.
    if ($is_single_node) {
      $unique_id = $node->field_ds_unique_id[0]['value'];
      if (empty($unique_id)) {
        $unique_id = $nid;
      }
      $filename = "dataset.$unique_id." . date('Y-m-d') . ".$format";
    }

    $data = dms_ds_upload_retrieve_node($node, $all_fields);
    $data_list[$nid] = array();
    foreach ($ready_list['fieldname'] as $fieldname) {
      $data_list[$nid][] = $data[$fieldname];
    }
  }

  switch ($format) {

    case 'csv':
      header("Cache-Control: no-store, no-cache");
      header('Content-Disposition: attachment; filename="' . $filename . '"');
      header("Content-type: text/csv");
      $outstream = fopen("php://output",'w');
      fputcsv($outstream, $ready_list['fieldname'], ',', '"');
      foreach ($node_ids as $nid) {
        array_walk($data_list[$nid], 'dms_ds_upload_parepare_data', 'csv');
        fputcsv($outstream, $data_list[$nid], ',', '"');
      }
      fclose($outstream);
      break;

    case 'xml':
      header('Content-type: "text/xml"; charset="utf8"');
      header('Content-disposition: attachment; filename="' . $filename . '"');
      $xml_string = "";
      foreach ($node_ids as $nid) {
        array_walk($data_list[$nid], 'dms_ds_upload_parepare_data', 'xml');
        $assoc_array = array_combine($ready_list['fieldname'], $data_list[$nid]);
        $xml_string .= '  <dataset>' . PHP_EOL . assocToXML($assoc_array, 2) . '  </dataset>' . PHP_EOL;
      }
      $xml_string = '<?xml version="1.0" encoding="UTF-8"?><datasets>' . PHP_EOL . $xml_string . '</datasets>';
      $xml_string = str_replace($GLOBALS['dms_ds_upload_delimiter']['xml']['tag_replacement_left'], '<' . $GLOBALS['dms_ds_upload_delimiter']['xml']['tag'] . '>', $xml_string);
      $xml_string = str_replace($GLOBALS['dms_ds_upload_delimiter']['xml']['tag_replacement_right'], '</' . $GLOBALS['dms_ds_upload_delimiter']['xml']['tag'] . '>', $xml_string);
      $xml = new SimpleXMLElement($xml_string);
      echo $xml->asXML();
      break;

    case 'xls':
      $download_path = file_directory_path() . '/dms_download';
      $filepath = $download_path . '/' . $filename;

      //create dir first
      if (!file_exists($download_path)) {
        mkdir ($download_path);
      }
      //use styled blank xls file as starting point.
      $empty_template = dirname(__FILE__) . '/templates/empty.template.xls';
      if (!file_exists($empty_template)){
        drupal_set_message(t("File error. Empty template file could not be loaded."));
        drupal_goto("node/$nid");
      }
      require_once 'Classes/PHPExcel/IOFactory.php';
      $objReader = PHPExcel_IOFactory::createReader('Excel5');
      $objPHPExcel = $objReader->load($empty_template);
      $objPHPExcel->setActiveSheetIndex(0);

      //prepare data.
      foreach ($node_ids as $nid) {
        array_walk($data_list[$nid], 'dms_ds_upload_parepare_data', 'xls');
      }

      //data column starts with 'B'
      $column = 'B';
      for ($i = 0; $i < count($ready_list['fieldname']); $i++) {
        $objPHPExcel->getActiveSheet()->setCellValue($column . '1', $ready_list['fieldname'][$i]);
        $objPHPExcel->getActiveSheet()->setCellValue($column . '2', $ready_list['fieldlabel'][$i]);
        //insert data starting from row 3
        $current_row = 3;
        foreach ($node_ids as $nid) {
          $objPHPExcel->getActiveSheet()->setCellValue($column . $current_row, $data_list[$nid][$i]);
          $current_row++;
        }
        $objPHPExcel->getActiveSheet()->getColumnDimension($column)->setAutoSize(true);
        $column++; //PHP's Perls-style ability to increment characters.
      }
      $objPHPExcel->getActiveSheet()->setSelectedCell('B3');
      $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
      $objWriter->save($filepath);

      if (@ $handle = fopen ($filepath, "r")) {

        $file_size = filesize($filepath);
        header("Cache-Control: no-store, no-cache");
        header("Content-Disposition: attachment; filename=$filename");
        header("Content-type: application/vnd.ms-excel");
        header("Content-length: $file_size");
        while(!feof($handle)) {
          $buffer = fread($handle, 2048);
          echo $buffer;
        }
        fclose ($handle);
      }
      else {
        drupal_set_message(t("File error. File could not be created."));
        drupal_goto("node/$nid");
      }
      file_delete($filepath);
      break;

    default:
      drupal_not_found();
  }

  exit;
}

/**
 * Prepare data for different cormats.
 */
function dms_ds_upload_parepare_data(&$data, $key, $format = '') {
  switch ($format) {

    case 'csv':
    case 'xls':
      if (!$data) {
        $data = NULL;
      }
      elseif (count($data) == 1) {
        //if there is "," inside the value, we add double quote to protect it.
        $data = strrpos($data[0], ",") === FALSE ? $data[0] : '"' . $data[0] . '"';
      }
      else {
        $data = '"' . implode('","', $data) . '"';
      }
      break;

    case 'xml':
      if ($data) {
        if (count($data) > 1) {
          $data = PHP_EOL . '      ' . $GLOBALS['dms_ds_upload_delimiter']['xml']['tag_replacement_left'] . implode($GLOBALS['dms_ds_upload_delimiter']['xml']['tag_replacement_right'] . PHP_EOL . '      ' . $GLOBALS['dms_ds_upload_delimiter']['xml']['tag_replacement_left'], $data) . $GLOBALS['dms_ds_upload_delimiter']['xml']['tag_replacement_right']. PHP_EOL . '    ';
        }
        else {
          $data = implode(' | ', $data);
        }
      }
      break;

  }
}


/**
 * Convert an asssociate array into xml string.
 */
function assocToXML($data_array, $tabCount=0) {
  $tabCount += 2;
  $tabSpace = "";
  $extraTabSpace = "";
  for ($i = 0; $i<$tabCount; $i++) {
    $tabSpace .= " ";
  }

  for ($i = 0; $i<$tabCount+1; $i++) {
    $extraTabSpace .= " ";
  }

  // parse the array for data and output xml
  $xml_string = null;
  foreach ($data_array as $tag => $val) {
    if (!is_array($val)) {
      $xml_string .= $tabSpace . "<$tag>" . htmlentities($val) . "</$tag>" . PHP_EOL;
    }
    else {
      $tabCount++;
      $xml_string .= $extraTabSpace . "<$tag>" . assocToXML($val, $tabCount) . PHP_EOL;
      $xml_string .= $extraTabSpace . "</$tag>" . PHP_EOL;
    }
  }

  return $xml_string;
}
