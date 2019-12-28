<?php
//login.php

include('db_connection.php');

if(isset($_SESSION['type']))
{
	header("location:index.php");
}

$message = '';

if(isset($_POST["login"]))
{
	$query = "
	SELECT * FROM user_details 
		WHERE user_email = :user_email
	";
	$statement = $connect->prepare($query);
	$statement->execute(
		array(
				'user_email'	=>	$_POST["user_email"]
			)
	);
	$count = $statement->rowCount();
	if($count > 0)
	{
		$result = $statement->fetchAll();
		foreach($result as $row)
		{
			if($row['user_status'] == 'Active')
			{
				if(password_verify($_POST["user_password"], $row["user_password"]))
				{
				
					$_SESSION['type'] = $row['user_type'];
					$_SESSION['user_id'] = $row['user_id'];
					$_SESSION['user_name'] = $row['user_name'];
					header("location:index.php");
				}
				else
				{
					$message = "<label>Wrong Password</label>";
				}
			}
			else
			{
				$message = "<label>Your account is disabled, Contact Master</label>";
			}
		}
	}
	else
	{
		$message = "<label>Wrong Email Address</labe>";
	}
}

?>


<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta
      name="viewport"
      content="width=device-width, initial-scale=1, shrink-to-fit=no"
    />
    <title>
      Basic Inventory
    </title>
    <!-- Fonts -->
    <link
      href="https://fonts.googleapis.com/css?family=Open+Sans:300,400,600,700"
      rel="stylesheet"
    />
    <!-- Icons -->
    <link href="assets/js/plugins/nucleo/css/nucleo.css" rel="stylesheet" />
    <link
      href="assets/js/plugins/@fortawesome/fontawesome-free/css/all.min.css"
      rel="stylesheet"
    />
    <!-- CSS Files -->
    <link href="assets/css/argon-dashboard.css?v=1.1.1" rel="stylesheet" />
  </head>

  <body class="bg-default">
    <div class="main-content">
      <!-- Navbar -->
      <!-- Header -->
      <div class="header bg-gradient-primary py-7 py-lg-8"></div>
      <!-- Page content -->
      <div class="container mt--8 pb-5">
        <div class="row justify-content-center">
          <div class="col-lg-5 col-md-7">
            <div class="card bg-secondary shadow border-0">
              <div class="card-body px-lg-5 py-lg-5">
                <form method="post" role="form">
                <?php echo $message; ?>
                  <div class="form-group mb-3">
                    <div class="input-group input-group-alternative">
                      <div class="input-group-prepend">
                        <span class="input-group-text"
                          ><i class="ni ni-email-83"></i
                        ></span>
                      </div>
                      <input
                        class="form-control"
                        placeholder="Email"
                        type="text"
                        name="user_email"
                        required
                      />
                    </div>
                  </div>
                  <div class="form-group">
                    <div class="input-group input-group-alternative">
                      <div class="input-group-prepend">
                        <span class="input-group-text"
                          ><i class="ni ni-lock-circle-open"></i
                        ></span>
                      </div>
                      <input
                        class="form-control"
                        placeholder="Password"
                        type="password"
                        name="user_password"
                        required
                      />
                    </div>
                  </div>
                  <div
                    class="custom-control custom-control-alternative custom-checkbox"
                  >
                    <input
                      class="custom-control-input"
                      id=" customCheckLogin"
                      type="checkbox"
                    />
                    <label class="custom-control-label" for=" customCheckLogin">
                      <span class="text-muted">Remember me</span>
                    </label>
                  </div>
                  <div class="text-center">
                    <button type="submit" name="login" class="btn btn-primary my-4">
                      Sign in
                    </button>
                  </div>
                </form>
              </div>
            </div>
            <div class="row mt-3">
              <div class="col-6">
                <a href="#" class="text-light"
                  ><small>Forgot password?</small></a
                >
              </div>
              <div class="col-6 text-right">
                <a href="#" class="text-light"
                  ><small>Create new account</small></a
                >
              </div>
            </div>
          </div>
        </div>
      </div>
      <footer class="py-5">
        <div class="container">
          <div class="row align-items-center justify-content-xl-between"></div>
        </div>
      </footer>
    </div>
    <!--   Core   -->
    <script src="assets/js/plugins/jquery/dist/jquery.min.js"></script>
    <script src="assets/js/plugins/bootstrap/dist/js/bootstrap.bundle.min.js"></script>
    <!--   Optional JS   -->
    <!--   Argon JS   -->
    <script src="assets/js/argon-dashboard.min.js?v=1.1.1"></script>
    <script src="https://cdn.trackjs.com/agent/v3/latest/t.js"></script>
    <script>
      window.TrackJS &&
        TrackJS.install({
          token: "ee6fab19c5a04ac1a32a645abde4613a",
          application: "argon-dashboard-free"
        });
    </script>
  </body>
</html>
