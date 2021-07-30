<script src="js/pace.min.js"></script>
<link rel="stylesheet" href="/css/pace-theme-minimal.css">
<?php
session_start();
if (isset($_SESSION['tuser'])) header("Location: index.php");
if (isset($_POST['username'])) {
	$username = $_POST['username'];
	$password = $_POST['password'];
	$dom = new DOMDocument();
    $dom->load("data/account.xml");
    $row = $dom->getElementsByTagName("Row");
	$found = -1;
	foreach ($row as $r) {
		if ($found > -1 && $username) {
			for (@$i = 0; $i < 5; $i++) @$a[$i] = $r->getElementsByTagName("Cell")->item($i)->nodeValue;
			if ($a[1] == $username) {
				if (($a[4]==0 && $password == $a[2]) || (md5($password) == $a[2])) {
					$_SESSION['tid'] = $a[0];
					$_SESSION['tuser'] = $a[1];
					$_SESSION['tname'] = $a[3];
					$_SESSION['tpass'] = $a[2];

					if (isset($_POST['remember'])) {
						setcookie("cooktname", $username, time()+60*60*24*100); 
						setcookie("cooktpass", $password, time()+60*60*24*100);
					}			
					else {
						setcookie("cooktname", "", time()-60*60*24*100); 
						setcookie("cooktpass", "", time()-60*60*24*100);
					}	
					$found++;
					break;
				}
			}
		}
		else $found++;
	}
	if ($found == 1) header("Location: index.php");
	else header("Location: login.php?err=1");
}	
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Đăng nhập &middot; CVT Judger</title>
    <meta name="description" content="">
    <meta name="author" content="">

    <!-- Le styles -->
    <link href="css/bootstrap.css" rel="stylesheet">
    <style type="text/css">
      body {
        padding-top: 100px;
        padding-bottom: 50px;
        background: url(images/09.jpg) no-repeat center center fixed; 
         -webkit-background-size: cover;
        -moz-background-size: cover;
        -o-background-size: cover;
        background-size: cover;
        /*background: linear-gradient(to right,yellow,purple);*/
      }
        input[type=checkbox]
        {
          /* Double-sized Checkboxes */
          -ms-transform: scale(1.7); /* IE */
          -moz-transform: scale(1.7); /* FF */
          -webkit-transform: scale(1.7); /* Safari and Chrome */
          -o-transform: scale(1.7); /* Opera */
          transform: scale(1.7);
          padding: 0px;
        }

        /* Might want to wrap a span around your checkbox text */
        .checkboxtext
        {
          /* Checkbox text */
          font-size: 100%;
          display: inline;
        }
      .form-signin {
        max-width: 500px;
        padding: 19px 29px 29px;
        margin: 0 auto 20px;
        background-color: #fff;
        border: 30px solid #e5e5e5;
        -webkit-border-radius: 5px;
           -moz-border-radius: 5px;
                border-radius: 10px;
        -webkit-box-shadow: 0 1px 2px rgba(0,0,0,.05);
           -moz-box-shadow: 0 1px 2px rgba(0,0,0,.05);
                box-shadow: 0 1px 2px rgba(0,0,0,.05);
      }
      .form-signin .form-signin-heading,
      .form-signin .checkbox {
        margin-bottom: 10px;
        font-weight: bold;
      }
      .form-signin input[type="text"],
      .form-signin input[type="password"] {
          font-weight: bold;
          border: 5px solid  #CC99FF;
          color: blue;
          font-size: 16px;
          height: auto;
          margin-bottom: 15px;
          border-radius: 15px;
          padding: 10px 20px;
      }
	  .form-signin .warning {
	    font-size: 14px;
  		color: red; 
  		margin-top: 8px;
  		text-align: center;
	  }

    </style>
    <link href="css/bootstrap-responsive.css" rel="stylesheet">
    <link rel="apple-touch-icon-precomposed" sizes="144x144" href="ico/apple-touch-icon-144-precomposed.png">
    <link rel="apple-touch-icon-precomposed" sizes="114x114" href="ico/apple-touch-icon-114-precomposed.png">
      <link rel="apple-touch-icon-precomposed" sizes="72x72" href="ico/apple-touch-icon-72-precomposed.png">
                    <link rel="apple-touch-icon-precomposed" href="ico/apple-touch-icon-57-precomposed.png">
                                   <link rel="shortcut icon" href="ico/favicon.png">
  </head>

  <body>
   <style type="text/css">
      
      .text-center{

        text-align: center;
      }
    </style>
     <div class="text-center">
    <div class="container">

      <form class="form-signin" method="POST" action="<?php echo $_SERVER['PHP_SELF']?>">
        <h2 class="form-signin-heading">Đăng nhập JUDGER</h2>
        <input type="text" name="username" class="input-block-level" placeholder="Username" <?php if (isset($_COOKIE['cooktname'])) echo "value='".$_COOKIE['cooktname']."'";?>>
        <input type="password" name="password" class="input-block-level" placeholder="Password" <?php if (isset($_COOKIE['cooktpass'])) echo "value='".$_COOKIE['cooktpass']."'";?>>
       
        <label class="checkbox" style="font-size: 18px;">
          <input type="checkbox" name="remember" value="remember" <?php if (isset($_COOKIE['cooktname'])) echo "checked='checked'" ?>>
          Nhớ mật khẩu
        </label>
        <button class="btn btn-large btn-primary" type="submit" style="font-size: 18px; font-weight: bold; ">Đăng nhập</button>
        <button class="btn btn-large btn-primary" type="button" onclick="dieu_huong()" style="font-size: 18px; font-weight: bold;">WEB UPFILE</button>
    </div>
        <script>
        function dieu_huong(){
            location.assign("UPFILE");
        }
    </script>
		<div class="warning" style="font-size:20px; color: #FF3333 ;font-weight: bold;"> <?php if (isset($_GET['err'])) echo "Sai tên đăng nhập hoặc mật khẩu!"; ?> </div>
      </form>

    </div> 

  </body>
</html>
