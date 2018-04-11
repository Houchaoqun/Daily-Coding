#!/usr/bin/env python  
# coding = utf-8
while 1:
	n = raw_input()

	if n != "":
		money = 1
		days_added = 1
		is_added = True
		i = 2

		while(i <= int(n)):
			temp_added = days_added

			if(is_added):
				while(i <= int(n)):
					if(temp_added > 0):
						money += 1
						i += 1
						temp_added -= 1
					else:
						break

				is_added = False

			else:
				money -= 1
				days_added += 1
				is_added = True
				i += 1

		print(money)


	else:
		break