Action()
{

web_cache_cleanup();
web_cleanup_cookies();
web_set_max_html_param_len("999999");

	web_set_sockets_option("SSL_VERSION", "AUTO");
lr_start_transaction("TC01_Launch");
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

	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=Welcome to JPetStore",
		LAST);

	web_url("petstore.octoperf.com", 
		"URL=https://petstore.octoperf.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
		if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC01_Launch",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC01_Launch",LR_FAIL);
        }
		
//lr_end_transaction("TC01_Launch",LR_AUTO);


	lr_start_transaction("TC02_Enter_the_store");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(31);
	
//jsessionid=B64460118931467CD75C1ECF7C253380">
file = fopen("C:\\Users\\vangkumar\\Desktop\\jsessionid.txt","w");

web_reg_save_param("C_jsessionid","LB=jsessionid=","RB=\">",LAST);

//viewCategory=&amp;categoryId=FISH"><img
web_reg_save_param("C_CategoryId","LB=categoryId=","RB=\"><",LAST);


	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=JPetStore Demo",
		LAST);

	web_url("Enter the Store", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
		
if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC02_Enter_the_store",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC02_Enter_the_store",LR_FAIL);
        }
        
   fprintf(file,"%s, \n",lr_eval_string("{C_jsessionid}"));
        
    fclose(file);

//count = atoi(lr_eval_string("{correlation_param_count}"));  // to save the values count in parameter
//        
//         hf = fopen("C:\\Users\\vangkumar\\Desktop\\jsessionid.txt", "w"); 
//
//         for(i=1; i<=count;i++)
//         {
//            sprintf("C_jsessionid","{correlation_param_%d}",i);
//
//            
//            fprintf(hf, "correlation_value=%s,\n", lr_eval_string("{C_jsessionid}"));  //to write all values in new line
//             
//         }
//        fclose( hf);

	lr_start_transaction("TC03_Sing_In");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(24);
//<input type="hidden" name="_sourcePage" value="Z3oTnLTWhFAcqkEna-cWMR7FQX_R2EnaRHD3UqO6SLhUA-1P8YjztbzL6OXz_glJ1BgrZelScYmye8w7gxVYQLCLam3Z4ttD1QCqRYMCDRc=" />
	web_reg_save_param("C_sourcePage","LB=sourcePage\" value=\"","RB=\" />",LAST);
	
	//<input type="hidden" name="__fp" value="vzbwKrTAu3W7e0qYzyyOlYmF8KjhTQQzgFrbD26W_7Ltp-ykf9TgG4sUXuPl_FLf" />
web_reg_save_param("C_fp","LB=fp\" value=\"","RB=\" />",LAST);


      	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=username and password",
		LAST);

 web_url("Sign In",
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid={C_jsessionid}?signonForm=", 
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
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid={C_jsessionid}?signonForm=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={P_UserName}", ENDITEM, 
		"Name=password", "Value={P_PassWord}", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value={C_sourcePage}", ENDITEM, 
		"Name=__fp", "Value={C_fp}", ENDITEM, 
		LAST);

	if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC03_Sing_In",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC03_Sing_In",LR_FAIL);
        }
	//lr_end_transaction("TC03_Sing_In",LR_AUTO);
	
	
	

	lr_start_transaction("TC04_CategoryId");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(34);
	
//viewProduct=&amp;productId=FI-SW-01">FI-SW-01</a>

web_reg_save_param("C_ProductId","LB=productId=","RB=\">",LAST);

	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=productId",
		LAST);

	web_url("sm_fish.gif", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId={C_CategoryId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
		
		if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC04_CategoryId",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC04_CategoryId",LR_FAIL);
        }

	//lr_end_transaction("TC04_CategoryId",LR_AUTO);
	
	
	
	

	lr_think_time(47);

	lr_start_transaction("TC05_Click_Product_ID");
	
	
	//viewItem=&amp;itemId=EST-1">EST-1</a></td
	web_reg_save_param("C_itemId","LB=itemId=","RB=\">",LAST);
	

	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=itemId",
		LAST);

	web_url("{C_ProductId}", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId={C_ProductId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId={C_CategoryId}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC05_Click_Product_ID",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC05_Click_Product_ID",LR_FAIL);
        }

	//lr_end_transaction("TC05_Click_Product_ID",LR_AUTO);

	lr_think_time(31);

	lr_start_transaction("TC06_Add_to_Cart");

	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=Sub Total",
		LAST);

	web_url("Add to Cart", 
		"URL=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId={C_itemId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId={C_ProductId}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC06_Add_to_Cart",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC06_Add_to_Cart",LR_FAIL);
        }

	//lr_end_transaction("TC06_Add_to_Cart",LR_AUTO);

	lr_think_time(42);

	lr_start_transaction("TC07_Proceed_To_Checkout");
	
//input type="hidden" name="_sourcePage" value="q3PN3Ui0gqXNUzwOpWZLZpzqqigsJupOjL7p3WAsNv8XeUOrJvFXxGnELjEg6eTOU_DDE9GiWJN0GYFmM08MMpacC2WC7uRiP1Wlt3gCrCo=" /><
	
web_reg_save_param("C_sourcePage1","LB=sourcePage\" value=\"","RB=\" />",LAST);

//input type="hidden" name="__fp" value="WD_wCDU_YzsGAxRyTZ3WiNLeJYSXWeBAJNREcU66P67IDHyZ13dwB0piwtZny36nitHOcyz10BvaUabWVeIgIJCVXLiHGp7UdjHEus8DJ1-g0a7gGFY17Q==" /><

web_reg_save_param("C_fp1","LB=fp\" value=\"","RB=\" />",LAST);

	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=Payment Details",
		LAST);

	web_url("Proceed to Checkout",
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId={C_itemId}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC07_Proceed_To_Checkout",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC07_Proceed_To_Checkout",LR_FAIL);
        }
	//lr_end_transaction("TC07_Proceed_To_Checkout",LR_AUTO);

	lr_start_transaction("TC08_Enter_Details & Continue");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_header("Origin", 
		"https://petstore.octoperf.com");

	lr_think_time(136);

	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=Address 1",
		LAST);

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
		"Name=order.expiryDate", "Value={P_ExpiryDate}", ENDITEM, 
		"Name=order.billToFirstName", "Value={P_FirstName}", ENDITEM, 
		"Name=order.billToLastName", "Value={P_LastName}", ENDITEM, 
		"Name=order.billAddress1", "Value={P_Address}", ENDITEM, 
		"Name=order.billAddress2", "Value={P_Address2}", ENDITEM, 
		"Name=order.billCity", "Value={P_City}", ENDITEM, 
		"Name=order.billState", "Value={P_State}", ENDITEM, 
		"Name=order.billZip", "Value={P_Zip}", ENDITEM, 
		"Name=order.billCountry", "Value={P_Country}", ENDITEM, 
		"Name=newOrder", "Value=Continue", ENDITEM, 
		"Name=_sourcePage", "Value={C_sourcePage1}", ENDITEM, 
		"Name=__fp", "Value={C_fp1}", ENDITEM, 
		LAST);

	web_set_sockets_option("TLS_SNI", "0");
	if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC08_Enter_Details & Continue",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC08_Enter_Details & Continue",LR_FAIL);
        }

	//lr_end_transaction("TC08_Enter_Details & Continue",LR_AUTO);

	lr_think_time(93);

	lr_start_transaction("TC09_Confirm");

	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=Card Number",
		LAST);

	web_url("Confirm", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC09_Confirm",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC09_Confirm",LR_FAIL);
        }

	//lr_end_transaction("TC09_Confirm",LR_AUTO);

	lr_think_time(33);

	lr_start_transaction("TC10_Return_to_Menu");

	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=Welcome",
		LAST);

	web_url("Return to Main Menu", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC10_Return_to_Menu",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC10_Return_to_Menu",LR_FAIL);
        }
        
	//lr_end_transaction("TC10_Return_to_Menu",LR_AUTO);

	lr_start_transaction("TC11_Sign_Out");

	web_reg_find("Search=Body",
		"SaveCount=TextCheck",
		"Text=BIRDS",
		LAST);

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
	
	if(atoi(lr_eval_string("{TextCheck}"))>0)
        {
        lr_end_transaction("TC11_Sign_Out",LR_PASS);

        }
        else

 

        {
            lr_end_transaction("TC11_Sign_Out",LR_FAIL);
        }

	//lr_end_transaction("TC11_Sign_Out",LR_AUTO);

	return 0;
}
