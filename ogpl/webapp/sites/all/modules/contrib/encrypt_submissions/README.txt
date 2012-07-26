; $Id$
=======================
Encrypt Submissions
(For Drupal 6)
=======================
Richard Peacock (richard@richardpeacock.com)

NOTE:  Initial backport to D6 (from D7) was done by user k8n (http://drupal.org/user/243127)


This module uses the jCryption plugin (http://www.jcryption.org) to encrypt any form
submission in Drupal using 265-bit public/private key encryption.
For example, you can use it to encrypt the login and registration
form, so a user's passwords are never transmitted in clear text.
This is similar to how SSL works to encrypt traffic.

It should be noted that this module is not a replacement for SSL, which
can protect against other types of attacks.  This module is intended
for those who desire some minimal security from hackers,
but either cannot afford an SSL certificate, or only need basic
protection of form data.  For full protection, you should purchase
an SSL certificate.


======================
Important Limitations
======================
Unlike the D7 version, this D6 version of encrypt_submissions requires jQuery 1.4.4, which
does not come packaged with Drupal 6.  So, a copy of jQuery 1.4.4 is included in this project.
As a result, some existing javascript may have trouble running on the same page
as a form which has encryption turned on.

If you plan on using this module in a production environment, please test
and re-test all of your pages which might have extra or unusual javascript requirements, to
make sure nothing breaks!


======================
Features
======================
 - Works on any Drupal forms-- login, search, content types, settings, and
   forms from other contributed modules.
 - 256-bit public/private key encryption.
 - The keys are generated freshly per-submission, reducing the chances of cycling attacks.
 - Administrators may specify that the module only encrypt certain form submissions,
   leaving other form submissions in the clear.
 - Can be used to encrypt passwords during login, similar to
   the Safer Login module for Drupal 6 (http://drupal.org/project/safer_login)
 - If the user has JavaScript disabled, then all form submissions still work
   using standard, unencrypted submissions.
 - Works with Libraries API


======================
Requirements
======================
 - This module requires you to download the jCryption libraries, located here:
   http://www.jcryption.org (version 1.2 or later)
   The "Production" download is all you need, though the "Package" download works
   as well.
 - These libraries were NOT programmed by this module's maintainer.  It was mostly
   programmed by Daniel Griesser, and comprises several other libraries by different
   authors.  Please visit http://www.jcryption.org/about for a full list of credits.

=======================
Restrictions
=======================
 - This module only works on forms which use POST as their method type.  This is most
   of the forms in Drupal, but possibly there are some contributed modules out there
   which use GET.
    
======================
Directions
======================

- Unpack the module files into /sites/all/modules/encrypted_submissions.

- Download the jCryption libraries (1.2 or later) and unpack them into:
  /sites/all/modules/encrypted_submissions/jcryption
  so that the jcryption.php file is located at:
  sites/all/modules/encrypt_submissions/jcryption/jcryption.php
  
- ** Important! ** Make sure the jcryption files are named the following:
  jcryption.php and jquery.jcryption.js
  Even if you choose to minify the js file, please make sure it is named
  simply jquery.jcryption.js.  

- If using Libraries API module, place files at:
    /sites/all/libraries/jcryption/*.*  (note jcryption is all lowercase)
  
- Enable the module, and be sure to enable the "access" permission for your users,
  or else no one will be able to use it.  If you are protecting the login and registration
  forms, be sure to give the "access" permission to anonymous users!

- Visit the configuration page to specify which forms you want it to work on.
