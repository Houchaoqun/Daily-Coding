import os

def excute(target_path):
	dataset_root = "./data.txt"
	with open(dataset_root, 'r') as dataset:
		with open(target_path, 'a+') as target:
			for item in dataset:
				item = item.replace("\n", "")
				item = item.replace("\r", "")
				item_list = item.split(" ")
				print(item_list[0])
				info = "{}|||{}|||{}\n".format(item_list[0], item_list[1], item_list[2])
				target.writelines(info)

if __name__=="__main__":

	target_path = "./top_k.txt"
	excute(target_path)
	
