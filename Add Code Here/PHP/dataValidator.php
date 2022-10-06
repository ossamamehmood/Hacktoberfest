<?php
class validator{
    public function email($entered_email){

        if (!filter_var($entered_email, FILTER_VALIDATE_EMAIL)) {
            $emailErr = "Invalid email format";
          }
    }

    public function url($entered_url) {
        if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i",$entered_url)) {
            $websiteErr = "Invalid URL";
          }
    }
}




?>