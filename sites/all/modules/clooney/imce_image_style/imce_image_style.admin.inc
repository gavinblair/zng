<?php
/**
 * @file
 * Admin Forms.
 *
 * @author Ying Ho <ying@openconcept.dk>
 */

/**
 * Admin Form for choosing image styles.
 */
function imce_image_style_admin_form($form, &$form_state) {
  $presets = array();
  $styles = image_styles();
  foreach ($styles as $name => $style) {
    $presets[$name] = $style['label'];
  }

  $form['imce_image_style_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable IMCE Image style'),
    '#default_value' => variable_get('imce_image_style_enable', FALSE),
  );

  $form['imce_image_style_preset'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Image styles to enable in IMCE'),
    '#options' => $presets,
    '#multiple' => TRUE,
    '#description' => t('Select image styles names that the user can choose when uploading image file via IMCE.'),
    '#default_value' => variable_get('imce_image_style_preset', array()),
  );

  return system_settings_form($form);
}