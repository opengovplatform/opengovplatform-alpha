; $Id $

This directory is where you need to place the jCryption files.

You can download them from: http://www.jcryption.org/

At the time of this writing, jCryption version 1.2 was
download and used.  Future versions will probably work fine also.

You have two options for how you wish to install the jCryption files.

-----------

Option #1:

Place them in this directory, so that your file structure looks something
like this:
  sites/all/modules/encrypt_submissions/jcryption/jcryption.php
  sites/all/modules/encrypt_submissions/jcryption/jquery.jcryption.js

(Regardless of if you minify the .js file or not, it must be named
as above)
  

-----------

Option #2:

** If you are using Libraries API module **
You may place jcryption.php and jquery.jcryption.js
into sites/all/libraries/jcryption/*.*
  (note that the folder name is "jcryption", all lowercase)
  
  
-----------  
  
** Please Note **
The jCryption libraries were NOT programmed by this module's maintainer.  
They were mostly
programmed by Daniel Griesser, and comprise several other libraries by different
authors.  Please visit http://www.jcryption.org/about for a full list of credits.