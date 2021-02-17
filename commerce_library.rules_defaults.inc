<?php

/**
 * @file
 * Default rule configurations for Commerce Library
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_library_default_rules_configuration() {
  $rules = array();


  $rules_export = '{ "commerce_ssr_library_stock_disable_add_to_cart_loan" : {
    "LABEL" : "Library: disable add to cart (loans)",
    "PLUGIN" : "reaction rule",
    "WEIGHT" : "1",
    "OWNER" : "rules",
    "TAGS" : [ "library" ],
    "REQUIRES" : [ "commerce_library", "commerce_ss", "rules", "commerce_stock" ],
    "ON" : { "commerce_stock_check_add_to_cart_form_state" : [] },
    "IF" : [
      { "commerce_library_loan_enabled_on_product" : { "commerce_product" : [ "commerce_product" ] } },
      { "commerce_ss_stock_enabled_on_product" : { "commerce_product" : [ "commerce_product" ] } },
      { "commerce_ss_stock_not_disabled" : { "commerce_product" : [ "commerce_product" ] } },
      { "NOT data_is" : {
          "data" : [ "commerce-product:commerce-stock" ],
          "op" : "\u003E",
          "value" : "0"
        }
      }
    ],
    "DO" : [
      { "commerce_stock_set_add_to_cart_form_state" : {
          "disabled" : "1",
          "text" : "All products are on loan",
          "class_name" : "out-of-stock"
        }
      }
    ]
   }
  }';

  $rules['commerce_ssr_library_stock_disable_add_to_cart_loan'] = rules_import($rules_export);

  return $rules;
}
