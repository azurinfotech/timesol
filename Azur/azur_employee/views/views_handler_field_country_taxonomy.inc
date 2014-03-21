<?php

class views_handler_field_country_taxonomy  extends views_handler_field {
  function query() {
    $this->ensure_my_table();
    $def = $this->definition;
    $def['table'] = 'taxonomy_term_data';
    $def['left_table'] = $this->table_alias;
    $def['left_field'] = $this->real_field;
    $def['field'] = 'tid';
    // $def['type'] = 'INNER';

    $join = new views_join();

    $join->definition = $def;
    $join->construct();
    $join->adjusted = TRUE;

    // use a short alias for this:
    $alias = $def['table'] . '_' . $this->table;

    $this->alias = $this->query->add_relationship($alias, $join, $alias . '_' . $this->real_field, $this->relationship);
    $this->field_alias = $this->query->add_field($this->alias, 'name', '');
  }
}