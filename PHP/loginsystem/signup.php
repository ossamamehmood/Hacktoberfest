


<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Registration page</title>
  </head>

  <body>
  
  <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST'){
        $name = $_POST['name'];
        $email = $_POST['email'];
        $pass = $_POST['pass'];
        $cpass = $_POST['cpass'];
      $showalert=false;
      $showerror=false;
      // Submit these to a database

      // Connecting to the Database
$servername = "localhost";
$username = "root";
$password = "";
$database = "loginsystemdb";
      // Create a connection
      $conn = mysqli_connect($servername, $username, $password, $database);
      // Die if connection was not successful
      if (!$conn){
          die("Sorry we failed to connect: ". mysqli_connect_error());
      }
      else{ 
        // Submit these to a database
        // Sql query to be executed 
        $existSql = "SELECT * FROM `loginid` WHERE emailid = '$email'";
        $result = mysqli_query($conn, $existSql);
        $numExistRows = mysqli_num_rows($result);
    if($numExistRows > 0){
        // $exists = true;
        echo "Email ID Already Exists";
        $showerror=true;
    }
    else{
        if($pass==$cpass){
        $sql = "INSERT INTO `loginid` ( `username`, `emailid`, `password`) VALUES ('$name', '$email', '$pass');";
        $result = mysqli_query($conn, $sql);
        echo "BOTH PASSWORDS DOES NOT MATCH !";
        $showalert=true;
      }
      else
      {
        $showerror=true;
      }
    }
        if($showalert==true){
          echo '<div class="alert alert-success alert-dismissible fade show" role="alert">
          <strong>Success!</strong> Your entry has been submitted successfully! And we are happy to inform that your account is made!
          <button type="button" class="close" data-dismiss="alert" aria-label="Close">
            <span aria-hidden="true">×</span>
          </button>
        </div>';
        }
        if($showerror==true){
            // echo "The record was not inserted successfully because of this error ---> ". mysqli_error($conn);
            echo '<div class="alert alert-danger alert-dismissible fade show" role="alert">
          <strong>Error!</strong> We regret to inform account not made!
          <button type="button" class="close" data-dismiss="alert" aria-label="Close">
            <span aria-hidden="true">×</span>
          </button>
        </div>';
        }
      
      

    }

} 

?>

  <div align="center" class="min-h-full flex items-center justify-center py-12 px-4 sm:px-6 lg:px-8">
  <div class="max-w-md w-full space-y-8">
    <div >
      <img class="mx-auto h-12 w-auto" src="https://png.pngtree.com/png-vector/20191003/ourmid/pngtree-user-login-or-authenticate-icon-on-gray-background-flat-icon-ve-png-image_1786166.jpg" 
      alt="Workflow" width="200" 
     height="200">
      <h2 class="mt-6 text-center text-3xl font-extrabold text-gray-900">Register your account</h2>
      <p class="mt-2 text-center text-sm text-gray-600">
       
      </p>
    </div>
    <form class="mt-8 space-y-6" action="/loginsystem/signup.php" method="POST">
      <input type="hidden" name="remember" value="true">
      <div class="rounded-md shadow-sm -space-y-px">
      <div>
          <label for="email" class="sr-only">Name</label>
          <input id="name" name="name" type="text" autocomplete="name" required class="appearance-none rounded-none relative block w-full px-3 py-2 border border-gray-300 placeholder-gray-500 text-gray-900 rounded-t-md focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 focus:z-10 sm:text-sm" placeholder="User Name">
        </div>
        <br>
        <div>
          <label for="email" class="sr-only">Email address</label>
          <input id="email" name="email" type="email" autocomplete="email" required class="appearance-none rounded-none relative block w-full px-3 py-2 border border-gray-300 placeholder-gray-500 text-gray-900 rounded-t-md focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 focus:z-10 sm:text-sm" placeholder="Email address">
        </div>
        <br>
        <div>
          <label for="pass" class="sr-only">Password</label>
          <input id="pass" name="pass" type="password" autocomplete="current-password" required class="appearance-none rounded-none relative block w-full px-3 py-2 border border-gray-300 placeholder-gray-500 text-gray-900 rounded-b-md focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 focus:z-10 sm:text-sm" placeholder="Password">
        </div>
      </div> 

      <br>
      <div>
          <label for="cpass" class="sr-only">Confirm Password</label>
          <input id="cpass" name="cpass" type="password" autocomplete="current-password" required class="appearance-none rounded-none relative block w-full px-3 py-2 border border-gray-300 placeholder-gray-500 text-gray-900 rounded-b-md focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 focus:z-10 sm:text-sm" placeholder="Confirm Password">
        </div>
      </div> 
        
<br>
      <div>
        <button type="submit" class="group relative w-full flex justify-center py-2 px-4 border border-transparent text-sm font-medium rounded-md text-white bg-indigo-600 hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500">
          <span class="absolute left-0 inset-y-0 flex items-center pl-3">
            <!-- Heroicon name: solid/lock-closed -->
            <svg class="h-5 w-5 text-indigo-500 group-hover:text-indigo-400" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 20 20" fill="currentColor" aria-hidden="true">
              <path fill-rule="evenodd" d="M5 9V7a5 5 0 0110 0v2a2 2 0 012 2v5a2 2 0 01-2 2H5a2 2 0 01-2-2v-5a2 2 0 012-2zm8-2v2H7V7a3 3 0 016 0z" clip-rule="evenodd" />
            </svg>
          </span>
          Sign Up
        </button>
      </div>
    </form>
    <br>
      <div class="text-sm">
          <a href="./login.php" class="font-medium text-indigo-600 hover:text-indigo-500">Sign in ? </a>
        </div>
      </div>

  </div>
</div>
  
  </body>
  </html>