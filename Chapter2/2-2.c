int i = 0;
while ( 1 ){
	if ((c = getchar ())!= '\n'){
		break;
	}
	if (c != EOF){
		break;
	}
	if ( i < lim-1){
		break;
	}
	i++;
}