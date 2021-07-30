<?php
date_default_timezone_set('Asia/Ho_Chi_Minh');
$grade = $_REQUEST["grade"];
$room = $_REQUEST["room"];
$subject = $_REQUEST["subject"];
$target_dir = "DIR_UPLOAD/".$subject.$grade.$room;
$uploadOk = 1;
$date = getdate();
$sb = "-";
$sb1= "_";
$target_file = $target_dir.$date['year'].$sb.$date['mon'].$sb.$date['mday'].$sb.$date['hours'].$sb.$date['minutes'].$sb.$date['seconds'].$sb1.basename($_FILES["fileToUpload"]["name"]);

if ($uploadOk == 0) {
 echo 'alert(File chưa được tải lên. Vui lòng kiểm tra lại)'; 
    
} 	else 
	{
   		if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) 
    	{
		 echo "<script>
           alert('File ".basename( $_FILES["fileToUpload"]["name"]). " đã được tải lên.');
            window.location.href='/UPFILE';
        </script>";
       		 
   		}
   		 else
   		 {

  	echo "<script>
           alert('File chưa đuợc chọn, vui lòng chon file để tải lên.');
            window.location.href='/UPFILE';
        </script>";
    }
}
?>