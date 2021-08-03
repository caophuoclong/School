const pw = document.getElementById("password");
const pwc = document.getElementById("password-confirm");
const err = document.getElementById("error-wrong-password");
const handleEvent = (e) => {
  if (e.target.value === pw.value) {
    err.innerHTML = "";
  } else {
    err.innerHTML =
      "<p class='error-repassword'>Nhap lai mat khau khong dung</p>";
  }
};
["change", "keydown"];
