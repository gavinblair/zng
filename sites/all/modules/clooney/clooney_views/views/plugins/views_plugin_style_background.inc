<?php

class views_plugin_style_background extends views_plugin_style {
  /**
  * Set default options
  */
  function option_definition() {
    $options = parent::option_definition();

    $options['background_field'] = array('default' => 'field_image');

    $options['grouping'] = array('default' => array());
    if ($this->uses_row_class()) {
      $options['row_class'] = array('default' => '');
      $options['default_row_class'] = array('default' => TRUE, 'bool' => TRUE);
      $options['row_class_special'] = array('default' => TRUE, 'bool' => TRUE);
    }
    $options['uses_fields'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);


    $form['row_class'] = array(
      '#title' => t('Row class'),
      '#description' => t('The class to provide on each row.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['row_class'],
    );

    $form['default_row_class'] = array(
      '#title' => t('Add views row classes'),
      '#description' => t('Add the default row classes like views-row-1 to the output. You can use this to quickly reduce the amount of markup the view provides by default, at the cost of making it more difficult to apply CSS.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['default_row_class'],
    );
    $form['row_class_special'] = array(
      '#title' => t('Add striping (odd/even), first/last row classes'),
      '#description' => t('Add css classes to the first and last line, as well as odd/even classes for striping.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['row_class_special'],
    );


    $field_labels = $this->display->handler->get_field_labels(TRUE);
    $form['background_field'] = array(
      '#type' => 'select',
      '#title' => 'Background Image Field',
      '#options' => $field_labels,
      '#default_value' => $this->options['background_field'],
    );
    return $form;
  }
}
