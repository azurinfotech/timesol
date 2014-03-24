<?php

class views_handler_field_azur_static extends views_handler_field {
  var $static_options = NULL;
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this -> static_options = array(
      1 => t('Type of Employee'),
      2 => t('Employee Request'),
      3 => t('Employee Id')
      );
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['static_value_type'] = array('default' => 0);
    return $options;
  }

  /**
   * Display the filter on the administrative summary
   */
  function admin_summary() {
    return $this -> static_options[$this -> options['static_value_type']];
  }

  function options_form(&$form, &$form_state) {
    asort($this -> static_options);
    $form['static_value_type'] = array(
      '#type' => 'select',
      '#title' => t('Select Value Type'),
      '#options' => $this -> static_options,
      '#default_value' => $this -> options['static_value_type'],
      '#required' => TRUE,
      '#empty_value' => 0,
    );
    parent::options_form($form, $form_state);
  }

  function render($values) {
    $value = $this -> get_value($values);
    $output = '';
    switch ($this->options['static_value_type']) {
      case 1 :
        $output = azur_employee_type($value);
        break;
		
	  case 2 :
        $output = request_status($value);
        break;		
				
		case 3 :
        $output = azur_employee_name($value);
        break;				
    }
    return $output;
  }

}
      