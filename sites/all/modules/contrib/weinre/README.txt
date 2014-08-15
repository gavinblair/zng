CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Terminology
 * Drupal Module
 
INTRODUCTION
-------------
http://people.apache.org/~pmuellr/weinre/docs/latest/

Weinre is a debugger for web pages, like FireBug (for FireFox) and Web 
Inspector (for WebKit-based browsers), except it's designed to work remotely, 
and in particular, to allow you debug web pages on a mobile device such 
as a phone.

TERMINOLOGY
------------
http://people.apache.org/~pmuellr/weinre/docs/latest/Running.html

When using weinre, there are three programs interacting with each other.

1. Debug 
  This is the HTTP server that you run from the weinre-node distribution. 
  It's the HTTP server that's used by the Debug Client and Debug Target.
  
2. Debug Client
  This is the Web Inspector user interface; the web page which displays the
  Elements and Console panels, for instance.

3- Debug Target
  This is your web page that you want to debug. This name (Debug Target) is
  also used to refer to the machine running the browser displaying the web 
  page. Since a design point of weinre is to allow debugging applications on 
  mobile devices, the debug target, when speaking of the machine, is your 
  mobile device. 

Both the Debug Client and the Debug Target communicate to the Debug Server via
HTTP using XMLHttpRequest (XHR).

Typically, you run both the Debug Client and the Debug Server on your 
desktop/laptop, and the Debug Target on your mobile device.

DRUPAL MODULE
-------------
The module injects a JavaScript code, provided by the Debug Server, into your 
web page, in order for it to function as a Debug Target.
