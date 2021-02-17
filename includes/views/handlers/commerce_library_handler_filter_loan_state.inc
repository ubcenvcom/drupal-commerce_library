<?php

class commerce_library_handler_filter_loan_state extends views_handler_filter_in_operator {

  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Loan status');
      $options = array();
      $info=commerce_library_loan_state_info();
      foreach ($info as $name => $data) {
        $options[$name] = check_plain($data['title']);
      }
      // asort($options);
      $this->value_options = $options;
    }
  }

}
