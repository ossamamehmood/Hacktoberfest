try:
	import requests as r, os, json, time, random
	from bs4 import BeautifulSoup as par
except ModuleNotFoundError:
	exit("Module not installed..")

links = "https://www.instagramsave.com/"
ua  = {"user-agent": "Mozilla/5.0 (Linux; Android 11; vivo 1904 Build/RP1A.200720.012; wv) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/83.0.4103.106 Mobile Safari/537.36"}
ses = r.Session()
data_args = []

path = "C:/Users/" #> edit according to your storage location
try:
	os.mkdir(path)
except:
	pass

#-> Color: d for default
col = lambda code: "\x1b[1;"+str(code)+"m"
p, h, k, m, u, c, d = col(97), col(92), col(93), col(91), col(95), col(96), col(00)
#<--------------------->

def animate(teks):
	logs = list("\|/-")
	for yeah in logs:
		print("\r"+p+"["+k+yeah+p+"] "+teks+" ", end="")
		time.sleep(0.13)

def get_data(url, redirect, type):
	vid = par(ses.get(links+redirect, headers=ua).text, "html.parser")
	token = vid.find("input",{"name":"token"})["value"]
	get = ses.post(links+"system/action.php", headers=ua, data={
		"url": url,
		"action": type,
		"token": token,
		"json": ""
	}).text
	return get

def download_url(**kwargs):
	yeah = "IGDL-"+str(random.randint(1, 9999))
	lank = kwargs["URL"]
	lonk = kwargs["TIPE"]
	try:
		run = r.get(lank, headers=ua)
	except:
		return False, False
	with open(path+"/"+yeah+"."+lonk, "wb") as sv:
		sv.write(run.content)
	return True, yeah+"."+lonk

def main_menu():
	os.system("clear")
	print("""
%s.___  ________________  .____
|   |/  _____/\______ \ |    |
|   /   \  ___ |    |  \|    |
|   \    \_\  \|    `   \    |___
|___|\______  /_______  /_______ \\
            \/        \/        \/
%s%s%s%s
%s%s%s%s
%s%s%s%s
%s[%s01%s] %sinstagram video downloader
%s[%s02%s] %sinstagram photo downloader
%s[%s03%s] %sinstagram highlights downloader
%s[%s04%s] %sinstagram stories downloader
%s[%s05%s] %sinstagram igtv downloader
%s[%s06%s] %sinstagram reels downloader
%s[%s00%s] %sexit program
	""" % (u,
		m, p, m, h, m, p, m, h,
		m, p, m, h, c, p, c, p,
		c, p, c, p, c, p, c, p,
		c, p, c, p, c, p, c, p,
		c, p, c, p,
		c, p, c, p,
	))
	pil = input("%s[%s?%s] Choose%s:%s " % (p,c,p,m,h))
	while pil == "" or not pil.isdigit():
		print("%s[%s!%s] Choose menu " % (p,m,p))
		pil = input("%s[%s?%s] Choose%s:%s " % (p,c,p,m,h))
	if pil in ["1","01"]:
		url = input("%s[%s?%s] URL video%s:%s " % (p,c,p,m,h))
		while url == "" or "http" not in url or "https" not in url:
			print("%s[%s!%s] URL must start with http or https" % (p,m,p))
			url = input("%s[%s?%s] URL video%s:%s " % (p,c,p,m,h))
		cek = get_data(url, "download-instagram-videos.php", "post")
	elif pil in ["2","02"]:
		url = input("%s[%s?%s] URL photo%s:%s " % (p,c,p,m,h))
		while url == "" or "http" not in url or "https" not in url:
			print("%s[%s!%s] URL must start with http or https" % (p,m,p))
			url = input("%s[%s?%s] URL photo%s:%s " % (p,c,p,m,h))
		cek = get_data(url, "instagram-photo-downloader.php", "post")
	elif pil in ["3","03"]:
		url = input("%s[%s?%s] Input username%s:%s " % (p,c,p,m,h)).replace("@","").lower()
		while url == "" or "http" in url or "https" in url:
			print("%s[%s!%s] just enter the username" % (p,m,p))
			url = input("%s[%s?%s] Input username%s:%s " % (p,c,p,m,h)).replace("@","").lower()
		cek = get_data("https://www.instagram.com/"+url, "instagram-highlights-downloader.php", "highlights")
	elif pil in ["4", "04"]:
		url = input("%s[%s?%s] Input username%s:%s " % (p,c,p,m,h)).replace("@","").lower()
		while url == "" or "http" in url or "https" in url:
			print("%s[%s!%s] just enter the username" % (p,m,p))
			url = input("%s[%s?%s] Input username%s:%s " % (p,c,p,m,h)).replace("@","").lower()
		cek = get_data("https://www.instagram.com/"+url, "instagram-story-downloader.php", "story")
	elif pil in ["5","05"]:
		url = input("%s[%s?%s] Input username%s:%s " % (p,c,p,m,h)).replace("@","").lower()
		while url == "" or "http" in url or "https" in url:
			print("%s[%s!%s] just enter the username" % (p,m,p))
			url = input("%s[%s?%s] Input username%s:%s " % (p,c,p,m,h)).replace("@","").lower()
		cek = get_data("https://www.instagram.com/"+url, "igtv-downloader.php", "igtvVideos")
	elif pil in ["6","06"]:
		url = input("%s[%s?%s] URL reels%s:%s " % (p,c,p,m,h))
		while url == "" or "http" not in url or "https" not in url:
			print("%s[%s!%s] URL must start with http or https" % (p,m,p))
			url = input("%s[%s?%s] URL reels%s:%s " % (p,c,p,m,h))
		cek = get_data(url, "reels-downloader.php", "post")		
	elif pil in ["0","00"]:
		exit("%s[%s-%s] Byee....\n" % (p,m,p))
	else:
		input("%s[%s×%s] Menu not found, enter to back..." %(p,m,p))
		main_menu()

	#-> execute variable cek
	z = json.loads(cek)
	if "error" in z:
		exit("%s[%s×%s] %s\n" %(p,m,p,z["error"]))
	print("\n        %sfound posts from %s%s%s\n" % (p, h, z["user"]["username"], p))
	num = 0
	for _ in z["medias"]:
		num += 1
		print(p+"["+c+str(num)+p+"] "+_["url"][:34]+"..."+h+_["fileType"])
		data_args.append({"url": _["url"], "type": _["fileType"]})
	print("\n%s[%s!%s] type 'all' for download all" % (p,m,p))
	pel = input("%s[%s?%s] Choose%s:%s " % (p, c, p, m, h))
	while pel == "":
		print("%s[%s!%s] choose the result" % (p,m,p))
		pel = input("%s[%s?%s] Choose%s:%s " % (p, c, p, m, h))
	if pel.lower() == "all":
		for sm in data_args:
			animate("Processing download")
			kyah, save = download_url(URL=sm["url"], TIPE=sm["type"])
			if kyah:
				print("\n"+p+"["+h+"✓"+p+"] Success: "+k+path+"/"+save)
			else:
				print("\n"+p+"["+m+"×"+p+"] Failed : "+m+sm["url"][:34]+"..."+k+sm["type"])
		input("%s[%s✓%s] enter to back... or CTRL+Z for exit >" %(p,h,p))
		main_menu()
	else:
		try:
			coeg = data_args[int(pel)-1]
		except:
			exit("%s[%s×%s] failed to parse array, try again\n" %(p,m,p))
		print("%s[%s!%s] Please wait.." %(p,k,p))
		kyah, save = download_url(URL=coeg["url"], TIPE=coeg["type"])
		if kyah:
			print("\n"+p+"["+h+"✓"+p+"] Success: "+k+path+"/"+save)
		else:
			print("\n"+p+"["+m+"×"+p+"] Failed : "+m+sm["url"][:34]+"..."+k+sm["type"])
		input("%s[%s✓%s] enter to back... or CTRL+Z for exit >" %(p,h,p))
		main_menu()


if __name__=="__main__":
	try:
		main_menu()
	except Exception as errno:
		print(m+"\n[ERROR] "+p+str(errno))
