<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en"> <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <link rel="shortcut icon" type="image/png" href="favicon.ico"/>
    <meta name="description" content="">
    <meta name="author" content="">
       <title>CVT &middot; Upload</title>
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
         background: url(images/07.jpg) no-repeat center center fixed; 
         -webkit-background-size: cover;
        -moz-background-size: cover;
        -o-background-size: cover;
        background-size: cover;
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
         <b><a class="navbar-brand" href="../">JUDGER</a></b>
           <b><a class="navbar-brand" href="manage.php">File Manager</a></b>
  
        </div>
      </div>
    </div>
    <div class="text-center">
           <img src="images/logo.png" height="200" vspace="5" style="margin-top: 5px">
    </div>
   <div class="jumbotron">
      <div class="container">
  
    <center><h1 style="color:red"><b><code>CVT UPLOAD ONLINE</code></b></h1></center>
    <center><h3 style="color:red"><b><code>Vui lòng liên hệ admin nếu xảy ra lỗi!!</code></b></h3></center>
<div class="text-center">
  <form action="upload.php" method="post" enctype="multipart/form-data">
   <div class="file-upload">
      <div class="file-select">
        <div class="file-select-button" id="fileName" style="font-size: 15px">Choose File</div>
        <div class="file-select-name" id="noFile" style="font-size: 15px">No file chosen...</div> 
        <input type="file" name="fileToUpload" id="fileToUpload"><br>
      </div>
  </div>
  <br>
   <p style="font-size: 25px; font-weight: bold;">MÔN HỌC: <select id="subject" name="subject" style="font-size: 25px; font-weight: bold; border: 10px; border-radius: 5px">
                        <option value="TOAN/" >TOÁN</option>
                        <option value="VATLY/">VẬT LÝ</option>
                        <option value="HOA/">HOÁ HỌC</option>
                        <option value="SINH/">SINH</option>
                        <option value="VAN/">NGỮ VĂN</option>
                        <option value="TIENGANH/">TIẾNG ANH</option>
                        <option value="LICHSU/">LỊCH SỬ</option>
                        <option value="DIALY/">ĐỊA LÝ</option>
        </select>
         <select id="grade" name="grade" style="font-size: 25px; font-weight: bold; border: 10px; border-radius: 5px">
                        <option value="10/" >Lớp 10</option>
                        <option value="11/" >Lớp 11</option>
                        <option value="12/" >Lớp 12</option>
        </select>
          <select id="room" name="room" style="font-size: 25px; font-weight: bold; border: 10px; border-radius: 5px">
                        <option value="T/" >T</option>
                        <option value="VL/" >VL</option>
                        <option value="H/" >H</option>
                        <option value="SV/" >SV</option>
                        <option value="V/" >V</option>
                        <option value="TA/" >TA</option>
                        <option value="D/" >Đ</option>
                        <option value="LS/" >LS</option>
                        <option value="A/" >A</option>
        </select><br>
  <button type="submit" class="btn btn-success test" style="font-size:20px;font-weight:bold; border-radius: 10px;border: 10px; color: purple; margin-top: 10px;">Submit</button>

  </form>
</div>
<script type="text/javascript">
  $('#fileToUpload').bind('change', function () {
  var filename = $("#fileToUpload").val();
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

</div>
</div>
</div>
</div>
</div>
<div class="text-center">
      <hr>
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
