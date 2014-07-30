<?php

/**
 * @file
 * Functions for handling administrative tasks for weinre module.
 */

/**
 * Callback function weinre admin settings hook_menu item.
 */
function weinre_admin_config_form($form, &$form_state) {
  module_load_include('inc', 'weinre', 'inc/weinre.common');

  $form['page-title'] = array(
    '#markup' => '<h1>' . t('weinre Settings') . '</h1>',
  );

  if (weinre_is_debugging_enabled() && !weinre_is_server_listening()) {
    $form['production-warning'] = array(
      '#markup' => '<h3>' . t('weinre server is not running or configuration below is wrong.') . '</h3>',
    );
  }

  $form['debugging'] = array(
    '#type' => 'fieldset',
    '#title' => t('Debugging'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['debugging']['help'] = array(
    '#prefix' => '<p>',
    '#markup' => t('For information about the configuration below, please check <a href="@weinre_docs" target="_blank">weinre documentation</a>.', array('@weinre_docs' => 'http://people.apache.org/~pmuellr/weinre/docs/latest/Running.html')),
    '#suffix' => '</p>',
  );

  $form['debugging']['weinre_is_debugging_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable debugging with weinre'),
    '#description' => t('Check this box if you want to debug using weinre. Notice that you will still need to have weinre server running. <strong>Remember to disable debugging in production!</strong>'),
    '#default_value' => weinre_is_debugging_enabled(),
    '#return_value' => TRUE,
  );

  $form['debugging']['weinre_should_icon_be_displayed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add weinre icon to pages when debugging is enabled'),
    '#description' => t('If checked a weinre icon will be added to the pages. If the server seems not be running, a different icon will be shown.'),
    '#default_value' => weinre_should_icon_be_displayed(),
    '#return_value' => TRUE,
  );

  $form['debugging']['weinre_server_checking_timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('Server checking timeout'),
    '#description' => t('How many seconds to wait when checking if weinre server is listening. Defaults to <strong>%seconds second(s)</strong>', array('%seconds' => WEINRE_DEFAULT_SERVER_CHECKING_TIMEOUT)),
    '#default_value' => weinre_get_server_checking_timeout(),
  );

  $form['debugging']['weinre_bound_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Bound host'),
    '#description' => t(
      "Set this value to the same the <strong>--boundHost</strong> parameter was set when weinre was launched. If empty, <strong>%default_host</strong> will be used. <br/>
      <strong>Notice that <em>localhost</em> will map to the mobile device itself when you are debugging, so it's preferable to set it to the machine IP instead.</strong>",
      array('%default_host' => WEINRE_DEFAULT_BOUND_HOST)),
    '#default_value' => weinre_get_bound_host(),
  );

  $form['debugging']['weinre_http_port'] = array(
    '#type' => 'textfield',
    '#title' => t('HTTP port'),
    '#description' => t('Set this value to the same the <strong>--httpPort</strong> parameter was set when weinre was launched. If empty, <strong>%default_port</strong> will be used.', array('%default_port' => WEINRE_DEFAULT_HTTP_PORT)),
    '#default_value' => weinre_get_http_port(),
    '#element_validate' => array('weinre_admin_validate_http_port'),
  );

  return system_settings_form($form);
}

/**
 * Element validate callback for http port admin configuration field.
 */
function weinre_admin_validate_http_port($element, &$form_state, $form) {
  if ($form_state['values']['weinre_is_debugging_enabled']) {
    $is_invalid_number = preg_match('/[^0-9]/', $element['#value']);
    if ($is_invalid_number || $element['#value'] < 0 || $element['#value'] > WEINRE_MAXIMUM_HTTP_PORT_VALUE) {
      form_error(
        $element,
        t('%field should be a number greather than or equal to %min_value and less than or equal to %max_value', array(
          '%field' => $element['#title'],
          '%min_value' => 0,
          '%max_value' => WEINRE_MAXIMUM_HTTP_PORT_VALUE,
        ))
      );
    }
  }
}
