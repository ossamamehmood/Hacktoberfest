<?php
    #send chat with telegram bot to group

    $apiToken = "<YOUR TOKEN ID>"; #your token id
    $string = 
            "<strong>Alert Request</strong>\n".
            '<strong>Name:</strong> testing' . "\n".
            '<strong>Date/Time:</strong> '.date('d-m-Y H:i') . "\n".
            '<strong>Message:</strong> testing uhuy'; #if your request is html create here

    $data = [
        'chat_id' => '12343343434', #your group chat id 
        'text' => $string,
        'parse_mode' => "html"
    ]; #content request
    $response = file_get_contents("https://api.telegram.org/bot$apiToken/sendMessage?" . http_build_query($data) ); #url request

    echo $response;
    die();
?>