vuser_init()
{
	char* s;
	
	web_url("Webtours",
		"URL=http://localhost:1080/Webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_find("Text=Your username is taken",
		"SaveCount=CheckUniqUser",	             
		LAST);
	
	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={user}{number}", ENDITEM, 
		"Name=password", "Value=1", ENDITEM, 
		"Name=passwordConfirm", "Value=1", ENDITEM, 
		"Name=firstName", "Value=vit{number}", ENDITEM, 
		"Name=lastName", "Value=koval{number}", ENDITEM, 
		"Name=address1", "Value=street{number}", ENDITEM, 
		"Name=address2", "Value=city{number}", ENDITEM, 
		"Name=register.x", "Value=47", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);
	
		s = lr_eval_string("{CheckUniqUser}");
		i = atoi(s);
		
		if (i == 1) {
			
			lr_output_message("ERROR! ERROR! Username is taken! Please choose another!!! You can't create a ticket!!!");
			
		} else {
		
		lr_output_message("Iteration is: %s",lr_eval_string("{number}"));
		lr_output_message("Create  user is: %s",lr_eval_string("{user}{number}"));
		}
		
			

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	return 0;
}
