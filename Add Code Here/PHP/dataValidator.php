<?php
$Error = array();
if ($_SERVER['REQUEST_METHOD']=="POST") {
    class validator
    {
        public function email($entered_email)
        {
            if (!filter_var($entered_email, FILTER_VALIDATE_EMAIL)) {
                $Error = "Invalid email address";
                return $Error;
            }
        }

        public function url($entered_url)
        {
            if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i", $entered_url)) {
                $Error = "Invalid URL";
                return $Error;
            }
        }

        public function phone_number_zm_format($phone_number_zm_format)
        {
            if (!preg_match('/^(09|07)[5|6|7][0-9]{7}$/', $phone_number_zm_format)) {
                $Error = "Your phone number is invalid. Your phone must begin with either 096,097,095,076,077, or 075";
           return $Error;
            }
        }

        public function nrc_zm_format($nrc_zm_format)
        {
            if (!preg_match('/^(\d{6})\/\d{2}\/\d{1}$/', $nrc_zm_format)) {
                $Error = "Your NRC is invalid. Your NRC must be in this format ******/**/*";
                return $Error;
            }
        }

        public function first_name_only($firstName)
        {
            if (!preg_match('/^[a-zA-Z]{2,50}$/', $firstName)) {
                $Error = "Your name is invalid. Ensure your first name does not contain spaces";
                return $Error; 
            }
        }

        public function full_name_only($fullName)
        {
            if (!preg_match('/([a-zA-Z]){2,50}\s([a-zA-Z]){2,50}$/', $fullName)) {
                $Error = "Your Full Name is invalid";
                return $Error;
            }
        }
    }
     
    $validate = new validator();
    $EmailErr = $validate->email($_POST['email']);
    $UrlErr = $validate->url($_POST['url']);
    $PhoneErr = $validate->phone_number_zm_format($_POST['phone']);
    
    $Error = array($EmailErr,$UrlErr,$PhoneErr);
   
    
}

?>




<!-- TESTING VALIDATION -->

<!DOCTYPE html>

<head>
    <title>TESTING VALIDATION</title>
    <meta charset="utf-8" />
    <meta name="developer" content="Chanda Chewe" />
    <meta name="description" content="VALIDATION" />
    <meta name="revised" content="08/10/2022" />
    <meta name="viewport" content="width=device-width,initial-scale=1.0" />


  </head>

<body>
    <style>
         body {
        font-family: Arial, Helvetica, sans-serif;
       font-weight:bold;
       font-size:small;
       background-color:#ccc;
           
    }
        #name{
            width:90%;
                        padding:12px 20px;
                        margin:8px 0;
                        display:inline-block;
                        border:1px solid #ccc;
                        box-sizing:border-box;  
        }
#upload{
    background-color:#4CAF50;
                        color:white;
                        padding:14px 20px;
                        margin:8px 0;
                        border:none;
                        width:70%;
                        cursor:pointer;
}
form{
    border: 3px solid #f1f1f1;
                margin-top: 10px;
                width: 30%;
                background-color: #f1f1f1;  
                margin-bottom:20px;          
                        
}
@media screen and (max-width:1025px) {
            form{
                        border:3px solid #f1f1f1;
                        margin-top:10px;
                        width:90%;
            }
        }
    </style>
    <center>
      
        
  <form action="<?PHP echo ($_SERVER['PHP_SELF']); ?>";  method="POST">
    <h3>TESTING VALIDATION</h3>

    

    <h4>INPUTS</h4>
    <!--Show Errors here -->
    
  
  <?php  foreach ($Error as $Errors){?>
    <ul> 
<li><span class="error" style="color:red"> <?php echo $Errors;?></span></li>
  </ul>
    
   <?php
} 
?>
   
    <!--End Showing Errors--> 


        <input type="text" name="email" id="name" placeholder="Enter Email" ></br>
        
        <input type="text" name="url" id="name" placeholder="Enter URL" ></br>
        <input type="number" name="phone" id="name" placeholder="Enter phone number"></br>
        <!--
        <input type="text" name="nrc" id="name" placeholder="Enter nrc"></br>
        <input type="text" name="firstname" id="name" placeholder="Enter first name"></br>
        <input type="text" name="fullname" id="name" placeholder="Enter full name"></br>
    -->
        <input type="submit" value="submit" id="upload">
        <br><br>
        
        </form>
        <!--notes-->
        <small style="color:blue">For Further inquiries contact whatever@whatever.com</small>
      
    </center>
    
        
</body>
</html>