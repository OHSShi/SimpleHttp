#include	<iostream>

#include	"HttpResponse.hpp"

int main( int argc , char** argv )
{
	int				ret;
	HttpResponse		ht;

#if 0
#if 0
	string	rResponse	= "HTTP/1.1 200 OK\r\n"
		"Content-Type: application/json\r\n"
		"Date: Sun, 28 Jun 2015 01:53:41 GMT\r\n"
		"Transfer-Encoding: chunked\r\n"
		"\r\n"
		"8\r\n"
		"ABCDEFG\n\r\n";
#else
	string	rResponse	= "HTTP/1.1 200 OK\r\n"
		"Content-Type: application/json\r\n"
		"Content-Length: 8\r\n"
		"Date: Sun, 28 Jun 2015 01:53:41 GMT\r\n"
		"\r\n"
		"ABCDEFG\n\r\n";
#endif
#endif

	string	rResponse = "HTTP/1.1 200 OK\r\n"
		"Content-Type: application/json\r\n"
		"Date: Wed, 15 Jul 2015 01:27:53 GMT\r\n"
		"Transfer-Encoding: chunked\r\n"
		"\r\n"
		"800\r\n"
		"[{\"Command\":\"/bin/bash\",\"Created\":1436862924,\"Id\":\"8f651125e40605166bce455ec7da18d8b01e936c9386915ad9fa17977bf35d86\",\"Image\":\"mme00a:latest\",\"Names\":[\"/gloomy_feynman\"],\"Ports\":[],\"Status\":\"Exited (0) 16 hours ago\"}\n"
		",{\"Command\":\"/bin/bash\",\"Created\":1436856027,\"Id\":\"ba197a7dd76403a55e68b40a6d8b0aa93047fdf7925b52016160dfbe97e7910b\",\"Image\":\"bfad3fe895ec\",\"Names\":[\"/spgw00a\"],\"Ports\":[],\"Status\":\"Up 18 hours\"}\n"
		",{\"Command\":\"/bin/sh -c 'yum install -y tar ed ksh gcc file which crontabs vim gdb telnet openssh-clients openssh-server pciutils vsftpd ntp xinetd gnome-bluetooth.x86_64 python-setuptools tcpdump'\",\"Created\":1436851745,\"Id\":\"549d0512bb3a1cde164e0c8cdbd9eb684eec5927ff6d11d41337dd2f7e560e23\",\"Image\":\"61a3bc6ebd9e\",\"Names\":[\"/sad_franklin\"],\"Ports\":[],\"Status\":\"Exited (1) 19 hours ago\"}\n"
		",{\"Command\":\"/bin/bash\",\"Created\":1436851430,\"Id\":\"6abc8b3fe75fa30bf604f601a3a619cec6a092711c4453dc1c60b9ae0075d854\",\"Image\":\"initial:vepc\",\"Names\":[\"/focused_fermat\"],\"Ports\":[],\"Status\":\"Up 20 hours\"}\n"
		",{\"Command\":\"/bin/bash\",\"Created\":1436851384,\"Id\":\"a5731d7bd53441acecd29e503f891f3e221882b8ba627664daf6b42613fa546f\",\"Image\":\"mme_pkg:latest\",\"Names\":[\"/mme01a\"],\"Ports\":[],\"Status\":\"Up 19 hours\"}\n"
		",{\"Command\":\"/start.sh\",\"Created\":1436850282,\"Id\":\"b86486c8daf422a84ffa19fa104da0a7495d3c7dded1b311ceb4a80dcfcf3db8\",\"Image\":\"4674500f012a\",\"Names\":[\"/ems00a\"],\"Ports\":[],\"Status\":\"Up 20 hours\"}\n"
		",{\"Command\":\"/bin/bash\",\"Created\":1436837314,\"Id\":\"d7dcb9d08f9cab672e0d7f649cd49e815aa7d244fcb08e0b12433594076981f3\",\"Image\":\"bfad3fe895ec\",\"Names\":[\"/tmp\"],\"Ports\":[],\"Status\":\"Up 21 hours\"}\n"
		",{\"Command\":\"/bin/sh -c 'yum install -y tar ed ksh gcc file which crontabs vim gdb telnet openssh-clients openssh-server pciutils vsftpd ntp xinetd gnome-bluetooth.x86_64 python-setuptools tcpdump'\",\"Created\":1436440132,\"Id\":\"3a4f1caaa58ac4d6fc6134b04ce7795fb9c5ac08f2eb047e137e8bc76e91db88\",\"Image\":\"d332ceea171f\",\"Names\":[\"/ecstatic_perlman\"],\"Ports\":[],\"Status\":\"Exited (1) 5 days ago\"}\n"
		",{\"Command\":\"/bin/bash\",\"Created\":1436157725,\"Id\":\"4058baa510b12510e110\r\n"
		"3c3\r\n"
		"3a46d938cde0efe549d4ff8797b2909dffff108d63ea\",\"Image\":\"mme_pkg01:latest\",\"Names\":[\"/mme_pkg01\"],\"Ports\":[],\"Status\":\"Exited (0) 3 days ago\"}\n"
		",{\"Command\":\"/bin/bash\",\"Created\":1436156969,\"Id\":\"6b23818e3784b2498ad15cc6d43d566e73547af7b3a42be0d35be9a14277e97c\",\"Image\":\"ed1ca78e535d\",\"Names\":[\"/mme00a\"],\"Ports\":[],\"Status\":\"Up 16 hours\"}\n"
		",{\"Command\":\"/bin/bash\",\"Created\":1435982659,\"Id\":\"e0a7f6633c0c968016242cdebab95b163ee89ea5cad5d6d9740411d43ad58af3\",\"Image\":\"f5fb031b88ea\",\"Names\":[\"/spgw01a\"],\"Ports\":[],\"Status\":\"Up 21 hours\"}\n"
		",{\"Command\":\"/bin/bash\",\"Created\":1434860655,\"Id\":\"152916f3a49ff4d642a791d9b16f0e720ecf08be8979442de7c19a8ec9e75e90\",\"Image\":\"c113bb812b26\",\"Names\":[\"/cocky_mcclintock\"],\"Ports\":[],\"Status\":\"Exited (0) 3 weeks ago\"}\n"
		",{\"Command\":\"/bin/bash\",\"Created\":1434852412,\"Id\":\"65dcd46c1fbc84619a303b5f06d4c2f51e0bf25e959f94007d8ceebd12561a98\",\"Image\":\"c113bb812b26\",\"Names\":[\"/silly_einstein\"],\"Ports\":[],\"Status\":\"Exited (0) 3 weeks ago\"}\n"
		"]\r\n"
		"0\r\n";

	ret = ht.Analyze( rResponse );
	if( ret < 0 )
	{
		cout << "Fail" << endl;
		return	-1;
	}
	else if( ret == HTTP_MSG_ANALYZE_NOT_CLOSE )
	{
		cout << "Message Not Close" << endl;
		return -1;
	}
	else if( ret == HTTP_MSG_ANALYZE_CHUNKED )
	{
		cout << "------ CHUNKED --------" << endl;
	}

	ht.Print();

	return	0;
}
