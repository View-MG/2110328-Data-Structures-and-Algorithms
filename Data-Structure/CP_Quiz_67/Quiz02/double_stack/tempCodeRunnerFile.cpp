
	std::string type;
	while(true) {
		query++;
		cin >> type;
		if(type=="s") {
			if(dataType==1)
				cout << stk.size() << '\n';