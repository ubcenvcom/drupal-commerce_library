<?php
class commerce_library_handler_field_loan_link extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['loan_id'] = 'loan_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $loan_id = $this->get_value($values, 'loan_id');

    $links = menu_contextual_links('commerce-library', 'admin/commerce/loans', array($loan_id));

    return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
  }
}
