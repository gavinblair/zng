<?php



function clooney_views_views_plugins() {

  return array(
    'style' => array( //declare the background style plugin
      'background' => array(
        'title' => t('Unformatted with Background Images'),
        'theme' => 'views_view_background',
        'help' => t('Displays a background image based on a selected field.'),
        'handler' => 'views_plugin_style_background',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',       
      ),
    ),
    'row' => array( //declare the unformatted row plugin
      'unformatted' => array(
        'title' => t('Unformatted'),
        'help' => t('(Displays the unformatted data for each row from the views query with each row on a new line. Set as | for background.'),
        'handler' => 'views_plugin_row_unformatted',
        'theme' => 'views_view_row_unformatted',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      )
     )  
  );
}

function render() {
    if ($this->uses_row_plugin() && empty($this->row_plugin)) {
      debug('views_plugin_style_default: Missing row plugin');
      return;
    }

    // Group the rows according to the grouping instructions, if specified.
    $sets = $this->render_grouping(
      $this->view->result,
      $this->options['grouping'],
      TRUE
    );

    return $this->render_grouping_sets($sets);
  }