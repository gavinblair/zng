<?php

class views_plugin_row_unformatted extends views_plugin_row {
	function option_definition() {
		$options = parent::option_definition();
		$options['separator'] = array('default' => '|');

		return $options;
	}
	function options_form(&$form, &$form_state) {
		$fields = $this->display->handler->get_option('fields');
		$options = array();
		foreach ($fields as $field => $info) {
			$handler = views_get_handler($info['table'], $info['field'], 'field');
			if ($handler) {
				$options[$field] = $handler->ui_name();
			}
		}

		$form['separator'] = array(
		'#title' => t('Separator'),
		'#type' => 'textfield',
		'#size' => 10,
		'#default_value' => isset($this->options['separator']) ? $this->options['separator'] : ',',
		'#description' => t('The separator is placed between fields.'),
		);
	}
	function render() {
		watchdog('clooney', 'renderrow');
		if (empty($this->row_plugin)) {
			vpr('views_plugin_style_default: Missing row plugin');
			return;
		}
		$rows = array();
		foreach ($this->view->result as $row) {
			$rows[] = $this->row_plugin->render($row);
		}
		return theme($this->theme_functions(), $this->view, $this->options, $rows);
	}
}