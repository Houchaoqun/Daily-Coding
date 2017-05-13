from django.contrib import admin
from app_SettingFormula.models import *

# Register your models here.
class FormulaAdmin(admin.ModelAdmin):
	pass

admin.site.register(Formula, FormulaAdmin)