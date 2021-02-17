<?php

function commerce_library_views_default_views() {
$views=array();

include_once('commerce_library.views.user.inc');
$views[$view->name] = $view;

include_once('commerce_library.views.admin.inc');
$views[$view->name] = $view;

return $views;
}

