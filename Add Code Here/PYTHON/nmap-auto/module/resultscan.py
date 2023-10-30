class ResultScan:
	
	def printDict(self, d):
		for k, v in d.items():
			if isinstance(v,dict):
				print("---------------")
				print("[ {0} ]" .format(k))
				print("---------------")
				self.printDict(v)            
			else:
				print("[+] - {0} " .format(k))
				if isinstance(v,list):
					for v2 in v:
						for key, value in v2.items():                    
							print("--> [ {0} : {1} ]" .format(key, value))
				else:
					print("--> [ {0} ]" .format(v))		
