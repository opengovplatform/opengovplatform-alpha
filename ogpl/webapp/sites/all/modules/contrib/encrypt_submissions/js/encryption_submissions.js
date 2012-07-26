// $Id$
/**
 * This will run at start up, and attach the jCryption behavior to 
 * all of the forms specified in Drupal.settings.encrypt_submissions.encryptForms
 *
 **/

// Assuming jQuery 1.4.4 was just loaded, 'jq' becomes our own, personal jQuery 1.4.4 :-)
var jq = jQuery.noConflict(true);

Drupal.behaviors.encrypt_submissions_startup = function () {

      // We need the ?q= syntax for people with clean URLs turned off
      jq.jCryption.defaultOptions.getKeysURL 
        = Drupal.settings.encrypt_submissions.baseUrl 
        + "?q=encrypt-submissions/generate-keypair&esrnd=" + encryptSubmissionsRandomString();

        // Loop through all the possible forms we should be affecting...
  jq.each(
    Drupal.settings.encrypt_submissions.encryptForms,
    function(form_id, el_id) { 
      jq("#encrypt_submissions_status_" + el_id).hide();
      jq("#" + el_id + ":input").removeAttr("disabled");
      jq("#" + el_id).jCryption({
        beforeEncryption: function() {
          // make the Encrypting status message show up.
          jq("#encrypt_submissions_status_" + el_id).show();
          return true;
        }
      });
    }
  );
};

/**
 * Returns a X-length string of random letters and numbers.
 * Used to construct a random URL which circumvents Drupal's caching system.
 **/
function encryptSubmissionsRandomString() {
	var chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXTZabcdefghiklmnopqrstuvwxyz";
	var length = 20;
	var randomstring = '';
	for (var i = 0; i < length; i++) {
		var rnum = Math.floor(Math.random() * chars.length);
		randomstring += chars.substring(rnum,rnum+1);
	}
	return randomstring;
}