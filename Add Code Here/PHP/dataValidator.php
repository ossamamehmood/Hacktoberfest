<?php
class validator{
    public function email($entered_email){

        if (!filter_var($entered_email, FILTER_VALIDATE_EMAIL)) {
            $emailErr = "Invalid email address";
          }
    }

    public function url($entered_url) {
        if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i",$entered_url)) {
            $websiteErr = "Invalid URL";
          }
    }

    public function phone_number_zm_format($phone_number_zm_format) {
        if (!preg_match('/^(09|07)[5|6|7][0-9]{7}$/',$phone_number_zm_format)){
            $phoneError = "Your phone number is invalid. Your phone must begin with either 096,097,095,076,077, or 075";
            }
    }

    public function nrc_zm_format($nrc_zm_format) {
        if (!preg_match('/^(\d{6})\/\d{2}\/\d{1}$/',$nrc_zm_format)){
            $nrcError = "Your NRC is invalid. Your NRC must be in this format ******/**/*";
            }
    }

    public function first_name_only($firstName) {
        if (!preg_match('/^[a-zA-Z]{2,50}$/',$firstName)){
            $firstNameError = "Your name is invalid. Ensure your first name does not contain spaces";
            }
    }

    public function full_name_only($fullName) {
        if (!preg_match('/([a-zA-Z]){2,50}\s([a-zA-Z]){2,50}$/',$fullName)){
            $fullNameError = "Your Full Name is invalid";
            }
    }
}




?>