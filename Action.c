Action()
{

	if (i == 1) {
	lr_output_message("");
	}
	
	if (i == 0) {
		
	lr_output_message("Create ticket");
	lr_output_message("");
	
	web_reg_save_param_ex(
		"ParamName=SeatingPref",
		"LB=seatPref\" value=\"",
		"RB=\"",
		"Ordinal={Random1}",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=TypeofSeat",
		"LB=seatType\" value=\"",
		"RB=\"",
		"Ordinal={Random2}",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=RoundTrip",
		"LB=roundtrip\" value=\"",
		"RB=\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=CostticketOut",
		"LB=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ordinal={Random3}",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=CostticketReturn",
		"LB=\"returnFlight\" value=\"",
		"RB=\"",
		"Ordinal={Random4}",
		SEARCH_FILTERS,
		LAST);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={HomeCity}", ENDITEM, 
		"Name=departDate", "Value=04/25/2020", ENDITEM, 
		"Name=arrive", "Value={ArriveCity}", ENDITEM, 
		"Name=returnDate", "Value=04/26/2020", ENDITEM, 
		"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
		"Name=roundtrip", "Value={RoundTrip}", ENDITEM, 
		"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
		"Name=seatType", "Value={TypeofSeat}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=34", ENDITEM, 
		"Name=findFlights.y", "Value=13", ENDITEM, 
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={CostticketOut}", ENDITEM, 
		"Name=returnFlight", "Value={CostticketReturn}", ENDITEM, 
		"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={TypeofSeat}", ENDITEM, 
		"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=44", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=vit{number}", ENDITEM, 
		"Name=lastName", "Value=koval{number}", ENDITEM, 
		"Name=address1", "Value=street{number}", ENDITEM, 
		"Name=address2", "Value=city{number}", ENDITEM, 
		"Name=pass1", "Value=vit{number} koval{number}", ENDITEM, 
		"Name=creditCard", "Value=111122223333444{number}", ENDITEM, 
		"Name=expDate", "Value=16/18", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
		"Name=seatType", "Value={TypeofSeat}", ENDITEM, 
		"Name=seatPref", "Value={SeatingPref}", ENDITEM, 
		"Name=outboundFlight", "Value={CostticketOut}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value={CostticketReturn}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=67", ENDITEM, 
		"Name=buyFlights.y", "Value=6", ENDITEM, 
		LAST);
	
	}

	return 0;
}