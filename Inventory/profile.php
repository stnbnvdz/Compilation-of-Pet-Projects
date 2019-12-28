<?php

include('db_connection.php');

if(!isset($_SESSION['type']))
{
    header("location:login.php");
}

$query = "
SELECT * FROM user_details
WHERE user_id = '".$_SESSION["user_id"]."'
";

$statement = $connect->prepare($query);
$statement->execute();
$result = $statement->fetchAll();
$name = '';
$email = '';
$user_id = '';
foreach($result as $row)
{
    $name = $row ['user_name'];
    $email = $row ['user_email'];
}

include('header.php');

?>

<div class="header pb-8 pt-5 pt-lg-8 d-flex align-items-center" style="min-height: 100px;">
      <!-- Mask -->
      <span class="mask bg-gradient-default opacity-8"></span>
      <!-- Header container -->
  
    </div>
    <!-- Page content -->
    <div class="container-fluid mt--7">
      <div class="row">

        <div class="col-xl-12 order-xl-1">
          <div class="card bg-secondary shadow">
            <div class="card-header bg-white border-0">
              <div class="row align-items-center">
                <div class="col-8">
                  <h3 class="mb-0">My account</h3>
                </div>
              </div>
            </div>
            <div class="card-body">
            <form method="POST" id= "edit_profile_form">
                <h6 class="heading-small text-muted mb-4">User information</h6>
                <span id="message"></span>
                <div class="pl-lg-4">
                  <div class="row">
                  <div class="col-lg-6">
                      <div class="form-group">
                        <label class="form-control-label">Name</label>
                        <input type="text" name="user_name" id="user_name" class="form-control form-control-alternative" value="<?php echo $name; ?>" required>
                      </div>
                    </div>
                    <div class="col-lg-6">
                      <div class="form-group">
                        <label class="form-control-label">Email address</label>
                        <input type="email" name="user_email" id="user_email" class="form-control form-control-alternative" required value="<?php echo $email; ?>">
                      </div>
                    </div>
                  </div>
                  <div class="row">
                    <div class="col-lg-6">
                        <div class="form-group">
                          <label class="form-control-label">New Password</label>
                          <input type="password" name="user_new_password" id="user_new_password" class="form-control form-control-alternative">
                        </div>
                      </div>
                      <div class="col-lg-6">
                    <div class="form-group">
                        <label class="form-control-label">Enter New Password</label>
                        <input type="password" name="user_re_enter_password" id="user_re_enter_password" class="form-control form-control-alternative">
                        <span id="error_password"></span>
                      </div>
                    </div>
                    
                    <div class="col-12 text-center">
                      <input type="submit" name="edit_prfile" id="edit_prfile" value="Edit" class="btn btn-info" style="width: 120px;height: 40px;">
                    </div>
                  </div>
                </div>
                <hr class="my-4" />
                </div>
              </form>
            </div>
          </div>
        </div>
      </div>
      <!-- Footer -->
      
    </div>
  </div>


<script>
$(document).ready(function(){
  $('#edit_profile_form').on('submit',function(event){
    event.preventDefault();
    if($('#user_new_password').val() != '')
    {
      if($('#user_new_password').val() !=$ ('#user_re_enter_password').val())
      {
        $('#error_password').html('<label class="text-danger">Password Not Match</label>');
      }
      else
      {
        $('#error_password').html('');
      }
    }
    $('#edit_prfile').attr('disabled', 'disabled');
    var form_data = $(this).serialize();
    $.ajax({
      url:"edit_profile.php",
      method:"POST",
      data:form_data,
      success: function(data)
      {
        $('#edit_profile').attr('disabled', false);
        $('#user_new_password').val('');
        $('#user_re_enter_password').val('');
        $('#message').html(data);
      }
    })
  });
});

</script>