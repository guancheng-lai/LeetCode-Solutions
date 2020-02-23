from datetime import date
class Solution:
	def daysBetweenDates(self, date1: str, date2: str) -> int:
		d0 = date(int(date1[0:4]), int(date1[5:7]), int(date1[8:10]))
		d1 = date(int(date2[0:4]), int(date2[5:7]), int(date2[8:10]))
		return abs((d1 - d0).days)
		