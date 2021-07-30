<?php
  include("init.php");
  include("config.php");
  include("functions.php")
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en"> <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <link rel="shortcut icon" type="image/png" href="favicon.ico"/>
    <meta name="description" content="">
    <meta name="author" content="">
       <title>CVT &middot; Judger</title>
    <link href="css/bootstrap.css" rel="stylesheet">
    <link href="css/jumbotron.css" rel="stylesheet">
    <link href="css/form.css" rel="stylesheet">
  <script src="js/jquery-latest.js"></script>
  <script>
    var refreshId = setInterval(function(){
      $('#logs').load('logs.php');
      $('#timer').load('timer.php');
    }, 1000);
  </script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
</head>
  <body>
    <style type="text/css">
      body{
         background: url(images/05.jpg) no-repeat center center fixed; 
         -webkit-background-size: cover;
        -moz-background-size: cover;
        -o-background-size: cover;
        background-size: cover;
         /*background: linear-gradient(to right,yellow,purple);*/*/
      }
      .text-center{

        text-align: center;
      }
      .test{
           height:40px;
          width:90px;
      }
    </style>
    <div class="navbar navbar-inverse navbar-fixed-top" role="navigation">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
         <b><a class="navbar-brand" href="../UPFILE">CVT - UPFILE</a></b>
         <b><a class="navbar-brand" href="/standings.php">Standing</a></b>
         <b><a class="navbar-brand" href="/wiki">Documents</a></b>
       <b><a class="navbar-brand" href="ide.php">IDE</a></b>
        <b><a class="navbar-brand" href="chatbox">Chat</a></b>
        <b><a class="navbar-brand" href="dashboard">Dashboard</a></b>
        </div>
    <div class="navbar-collapse collapse">
      <div class="navbar-form navbar-right"> 
        <a class="btn btn-success" href="repass.php" title="Đổi mật khẩu" style="margin-right:10px; border-radius: 10px;color: black; font-weight: bold; background-color: orange";>Thí sinh: <?php echo $_SESSION['tname']; ?></a>
       <a class="btn btn-success" href="logout.php" title="Đăng xuất" style="border-radius: 15px;margin-right:-80px; background-color: red; color: black; font-weight: bold;">Đăng xuất</a>  
    </div>
    </div>  
      </div>
    </div>
    <div class="text-center">
           <img src="images/logo.png" height="200" vspace="5" style="margin-top: 10px">
    </div>
   <div class="jumbotron">
      <div class="container">
    <center><h1 style="color:red"><b><code><?php echo $contestName; ?></code></b></h1></center>
   <center><a href="navigation.php"><h3 style="color:purple"><b><?php echo $description;?></b></h3></a></center>

<?php if ($duringTime > 0) { ?>
    <p style="font-size: 20; font-weight: bold; color: black">
      - Kì thi sẽ bắt đầu vào: <?php echo date("H:i:s F jS Y", $begintime); ?> <br/>
      - Thời gian: <?php echo $duringTime; ?> phút. <br/>
      <span id="timer"> </span>
    </p>
<?php } ?>

<div class="text-center">
  <form action="upload.php" method="post" enctype="multipart/form-data">
   <div class="file-upload">
      <div class="file-select">
        <div class="file-select-button" id="fileName" style="font-size: 15px">Choose File</div>
        <div class="file-select-name" id="noFile" style="font-size: 15px">No file chosen...</div> 
        <input type="file" name="file" id="file">
      </div>
  </div>
  <button type="submit" class="btn btn-success test" style="font-size:20px;font-weight:bold; border-radius: 10px;border: 10px; color: purple; margin-top: 10px;">Submit</button>
  </form>
</div>
<script type="text/javascript">
  $('#file').bind('change', function () {
  var filename = $("#file").val();
  if (/^\s*$/.test(filename)) {
    $(".file-upload").removeClass('active');
    $("#noFile").text("No file chosen..."); 
  }
  else {
    $(".file-upload").addClass('active');
    $("#noFile").text(filename.replace("C:\\fakepath\\", "")); 
  }
});
</script>
<div class="text-center">

    <div class="container">
      <!-- Example row of columns -->
      <div class="row">
    
    <div class="col-md-4">
          <h3><b>Problems:</b></h3>
<?php
    $time_remain = date_timestamp_get($startTime) + $duringTime*60 - time();
    $timesetup = $duringTime * 60;
    $dir = opendir($problemsDir);
    while ($file = readdir($dir)) { if ($time_remain <= $timesetup && $file!="." && $file!=".." && substr($file,0,strlen($file)-4)!="allproblems") {
      echo "<h4><a href='".$problemsDir."/".$file."'>".$file."</a></h4>";
    }}
    closedir($dir);
?>      
        </div>
    
        <div class="col-md-4">
          <h3><b>Log submission:</b></h3>
      <div id="logs"> Loading... </div>
     </div>
       <div class="col-md-4">
            <h3><b>Example Test:</b></h3>
       <?php
      $dir = opendir($examTestDir);
      while ($file = readdir($dir)) { if ($time_remain <= $timesetup && $file!="." && $file!=".." && substr($file,0,strlen($file)-4)!="allproblems") {
        echo "<h4><a href='".$examTestDir."/".$file."'>".$file."</a></h4>";
      }}
      closedir($dir);
       ?>      
          </div>

     
   </div>
    
</div>
</div>
</div>
</div>
</div>
<style type="text/css">


</style>
<div class="text-center">
    <footer>
          <script Language='Javascript'>
          <!--
          document.write(unescape('%3C%68%33%20%73%74%79%6C%65%3D%22%63%6F%6C%6F%72%3A%20%23%46%46%43%43%30%30%3B%22%3E%3C%62%3E%26%23%31%36%39%3B%20%43%72%65%61%74%65%64%20%62%79%20%50%68%61%6E%20%54%68%61%6E%68%20%41%6E%20%20%26%6C%73%61%71%75%6F%3B%20%4B%31%38%20%2D%20%32%31%20%26%72%73%61%71%75%6F%3B%3C%2F%62%3E%3C%2F%68%33%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%3C%65%6D%3E%3C%61%20%68%72%65%66%3D%22%68%74%74%70%73%3A%2F%2F%77%77%77%2E%66%61%63%65%62%6F%6F%6B%2E%63%6F%6D%2F%44%65%76%69%6C%43%35%31%2E%78%79%7A%2F%22%20%73%74%79%6C%65%3D%22%63%6F%6C%6F%72%3A%23%46%46%43%43%43%43%3B%66%6F%6E%74%2D%73%69%7A%65%3A%32%30%70%78%3B%22%3E%3C%62%3E%26%64%69%61%6D%73%3B%20%46%61%63%65%62%6F%6F%6B%3A%20%50%68%61%6E%20%54%68%61%6E%68%20%41%6E%3C%2F%62%3E%3C%2F%61%3E%3C%2F%65%6D%3E'));
      </script>
    </footer>
  </div> 
    <script src="js/bootstrap.min.js"></script>
  </body>

</html>
