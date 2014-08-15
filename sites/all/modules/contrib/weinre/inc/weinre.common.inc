<?php

/**
 * @file
 * Common functions for weinre module.
 */

/**
 * Check whether debugging is enabled.
 */
function weinre_is_debugging_enabled() {
  return variable_get('weinre_is_debugging_enabled', FALSE);
}

/**
 * Get the host where weinre server is running.
 */
function weinre_get_bound_host($return_default_if_empty = FALSE) {
  $host = variable_get('weinre_bound_host', '');
  if (empty($host) && $return_default_if_empty) {
    $host = WEINRE_DEFAULT_BOUND_HOST;
  }

  return $host;
}

/**
 * Get the port weinre server is listening to.
 */
function weinre_get_http_port($return_default_if_empty = FALSE) {
  $port = variable_get('weinre_http_port');
  if (empty($port) && $return_default_if_empty) {
    $port = WEINRE_DEFAULT_HTTP_PORT;
  }

  return $port;
}

/**
 * Whether or not to display a weinre icon on pages when debugging is enabled.
 */
function weinre_should_icon_be_displayed() {
  return variable_get('weinre_should_icon_be_displayed', TRUE);
}

/**
 * Get the http address of the weinre server.
 */
function weinre_get_server_address() {
  return 'http://' . weinre_get_bound_host(TRUE) . ':' . weinre_get_http_port(TRUE);
}

/**
 * Get the full js location to append to generated pages.
 */
function weinre_get_js_location() {
  return weinre_get_server_address() . WEINRE_JS_RELATIVE_PATH;
}

/**
 * How many seconds to wait when checking if weinre server is listening.
 */
function weinre_get_server_checking_timeout() {
  return variable_get('weinre_server_checking_timeout', WEINRE_DEFAULT_SERVER_CHECKING_TIMEOUT);
}

/**
 * Checks whether weinre server is listening on the configured host and port.
 */
function weinre_is_server_listening() {
  $is_listening = FALSE;

  $connection = @fsockopen(weinre_get_bound_host(TRUE), weinre_get_http_port(TRUE));
  if (is_resource($connection)) {
    $is_listening = TRUE;

    fclose($connection);
  }

  return $is_listening;
}
