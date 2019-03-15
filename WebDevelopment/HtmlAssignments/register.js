
function dob_validatation(d_o_b)
{
   var validformat=/^\d{2}\/\d{2}\/\d{4}$/ //Basic check for format validity
var returnval=false
if (!validformat.test(d_o_b.value))
alert("Invalid Date Format. Please correct and submit again.")
else{ //Detailed check for valid date ranges
var monthfield=d_o_b.value.split("/")[1]
var dayfield=d_o_b.value.split("/")[0]
var yearfield=d_o_b.value.split("/")[2]
var dayobj = new Date(yearfield, monthfield-1, dayfield)
if ((dayobj.getMonth()+1!=monthfield)||(dayobj.getDate()!=dayfield)||(dayobj.getFullYear()!=yearfield))
alert("Invalid Day, Month, or Year range detected. Please correct and submit again.")
else
returnval=true
}
if (returnval==false) d_o_b.select()
return returnval
}


function calculateAge()
{
  console.log("asdsad");
  var dob = document.registration.dob;
  var yearfield=dob.value.split("/")[2]
  if(dob_validatation(dob) === true)
  {
    today_date = new Date();
      today_year = today_date.getFullYear();
      today_month = today_date.getMonth();
      today_day = today_date.getDate();
      user_age = today_year - yearfield;
      var x;
      x = document.getElementById("age");
      x.value = user_age;
  }

}