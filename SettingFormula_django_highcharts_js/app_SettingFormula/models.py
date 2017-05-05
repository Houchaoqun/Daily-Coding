# -*- coding: utf-8 -*-
from django.db import models

# Create your models here.
# table T_Indicator_C
class Formula(models.Model):
	FormulaID = models.AutoField(primary_key = True)
	XValue = models.CharField(max_length = 100)
	KValue = models.CharField(max_length = 100)
	BValue = models.CharField(max_length = 100)
	FinalValue = models.CharField(max_length = 100)
	NOTE = models.CharField(max_length = 200, null = True)

	def __unicode__(self):
		return self.XValue + "_" + self.KValue + "_" + self.BValue