Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, br");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Not.A/Brand\";v=\"8\", \"Chromium\";v=\"114\", \"Google Chrome\";v=\"114\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("petstore.octoperf.com", 
		"URL=https://petstore.octoperf.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("TC02_Enter_the_store");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(31);

	web_url("Enter the Store", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TC02_Enter_the_store",LR_AUTO);

	lr_start_transaction("TC03_Sing_In");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(24);

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid=B64460118931467CD75C1ECF7C253380?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_header("Origin", 
		"https://petstore.octoperf.com");

	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid=B64460118931467CD75C1ECF7C253380?signonForm=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=j2ee", ENDITEM, 
		"Name=password", "Value=j2ee", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value=Z3oTnLTWhFAcqkEna-cWMR7FQX_R2EnaRHD3UqO6SLhUA-1P8YjztbzL6OXz_glJ1BgrZelScYmye8w7gxVYQLCLam3Z4ttD1QCqRYMCDRc=", ENDITEM, 
		"Name=__fp", "Value=vzbwKrTAu3W7e0qYzyyOlYmF8KjhTQQzgFrbD26W_7Ltp-ykf9TgG4sUXuPl_FLf", ENDITEM, 
		LAST);

	lr_end_transaction("TC03_Sing_In",LR_AUTO);

	lr_start_transaction("TC03_Click_Fish");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(34);

	web_url("sm_fish.gif", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TC03_Click_Fish",LR_AUTO);

	lr_think_time(47);

	lr_start_transaction("TC05_Click_Product_ID");

	web_url("FI-SW-01", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-01", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TC05_Click_Product_ID",LR_AUTO);

	lr_think_time(31);

	lr_start_transaction("TC06_Add_to_Cart");

	web_url("Add to Cart", 
		"URL=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-01", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TC06_Add_to_Cart",LR_AUTO);

	lr_think_time(42);

	lr_start_transaction("TC07_Proceed_To_Checkout");

	web_url("Proceed to Checkout", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-1", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TC07_Proceed_To_Checkout",LR_AUTO);

	lr_start_transaction("TC08_Enter_Details & Continue");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_header("Origin", 
		"https://petstore.octoperf.com");

	lr_think_time(136);

	web_submit_data("Order.action", 
		"Action=https://petstore.octoperf.com/actions/Order.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=order.cardType", "Value=Visa", ENDITEM, 
		"Name=order.creditCard", "Value=999 9999 9999 9999", ENDITEM, 
		"Name=order.expiryDate", "Value=12/03", ENDITEM, 
		"Name=order.billToFirstName", "Value=kumar", ENDITEM, 
		"Name=order.billToLastName", "Value=vinod", ENDITEM, 
		"Name=order.billAddress1", "Value=Kr Puram", ENDITEM, 
		"Name=order.billAddress2", "Value=#2000", ENDITEM, 
		"Name=order.billCity", "Value=Bangalore", ENDITEM, 
		"Name=order.billState", "Value=KA", ENDITEM, 
		"Name=order.billZip", "Value=94303", ENDITEM, 
		"Name=order.billCountry", "Value=India", ENDITEM, 
		"Name=newOrder", "Value=Continue", ENDITEM, 
		"Name=_sourcePage", "Value=q3PN3Ui0gqXNUzwOpWZLZpzqqigsJupOjL7p3WAsNv8XeUOrJvFXxGnELjEg6eTOU_DDE9GiWJN0GYFmM08MMpacC2WC7uRiP1Wlt3gCrCo=", ENDITEM, 
		"Name=__fp", "Value=WD_wCDU_YzsGAxRyTZ3WiNLeJYSXWeBAJNREcU66P67IDHyZ13dwB0piwtZny36nitHOcyz10BvaUabWVeIgIJCVXLiHGp7UdjHEus8DJ1-g0a7gGFY17Q==", ENDITEM, 
		LAST);

	web_set_sockets_option("TLS_SNI", "0");

	lr_end_transaction("TC08_Enter_Details & Continue",LR_AUTO);

	lr_think_time(93);

	lr_start_transaction("TC09_Confirm");

	web_url("Confirm", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TC09_Confirm",LR_AUTO);

	lr_think_time(33);

	lr_start_transaction("TC10_Return_to_Menu");

	web_url("Return to Main Menu", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TC10_Return_to_Menu",LR_AUTO);

	lr_start_transaction("TC11_Sign_Out");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("TLS_SNI", "1");

	lr_end_transaction("TC11_Sign_Out",LR_AUTO);

	return 0;
}
