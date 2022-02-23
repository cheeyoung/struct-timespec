/*
   23 Feb 2022 Created
*/

/*
   allocation and initialization of the pre element
   Used var for Safari on iOS
*/
var pre01 = document.createElement('pre') ;
pre01.id = "log" ;
pre01.class = "width: 300px" ;

/*
   insert the pre element to the section
*/
document.getElementById('section-log').insertBefore(pre01, document.getElementById('script-log')) ;
