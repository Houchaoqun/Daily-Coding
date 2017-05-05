# -*- coding: utf-8 -*-
from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from app_SettingFormula.models import *
from django.views.decorators.csrf import csrf_exempt

# Create your views here.

@csrf_exempt
def index(request):
    context = {}
    if request.method == 'POST':
        x_Value = request.POST.get('x_Value')
        k_Value = request.POST.get('k_Value')
        b_Value = request.POST.get('b_Value')

        # print x_list
        # print y_list
        # print k_list
        # Formula(XValue = x_Value, KValue = k_Value, BValue = b_Value).save()
        print x_Value
        print b_Value
        print k_Value
        context['x_Value'] = x_Value
        context['k_Value'] = k_Value
        context['b_Value'] = b_Value
        if x_Value and k_Value and b_Value:
        	context['expressions_list'] = get_IndicatorFormula_expression(x_Value, k_Value, b_Value)
        else:
        	print("x_Value or k_Value or b_Value exist null")

    return render(request, 'index.html', context)

def get_IndicatorFormula_expression(x_Value, k_Value, b_Value):
    X_list = x_Value.strip().split('_')
    K_list = k_Value.strip().split('_')
    B_list = b_Value.strip().split('_')

    # print "---"
    # print "X_list",X_list
    # print "B_list",B_list

    i = 0
    expressions_list = []

    # line and curve
    # find()函数找不到时返回为-1。
    for k in K_list:
        # print k
        expression = ""
        if k.find(";") == -1:
            print "=== line ==="
            if K_list[i]=='0':
                expression = "y = " + B_list[i]
            elif K_list[i]=='1':
                if (B_list[i]).find("-") == -1:
                    if B_list[i]==0:
                        expression = "y = x"
                    else:
                        expression = "y = x + " + B_list[i]
                else:
                    expression = "y = x " + B_list[i]
            else:
                if (B_list[i]).find("-") == -1:
                    if B_list[i]==0:
                        expression = "y = " + K_list[i] + "x"
                    else:
                        expression = "y = " + K_list[i] + "x + " + B_list[i]
                else:
                    expression = "y = " + K_list[i] + "x " + B_list[i]
        else:
            print "=== curve ==="
            curve_list = k.strip().split(';')
            j = 0
            curve_len = len(curve_list)
            print "curve_len = ",curve_len
            for j in range(curve_len):
                # exponent: 指数
                # curve_list[j]: 系数
                exponent = str(curve_len - j)
                print "exponent = ",exponent
                if curve_list[j] == "0":
                    expression = expression
                elif curve_list[j] == "1":
                    if exponent == "1":
                        expression = expression + " + x"
                    else:
                        expression = expression + " + " + "x^" + exponent
                elif curve_list[j] == "-1":
                    if exponent == "1":
                        expression = expression + " - x "
                    else:
                        expression = expression + " - x^" + exponent
                # coefficient > 0 except 1
                elif (curve_list[j]).find("-") == -1:
                    if exponent == "1":
                        # the begin position.
                        if j == 0:
                            expression = curve_list[j] + "x"
                        else:
                            expression = expression + " + " + curve_list[j] + "x"
                    else:
                        if j == 0:
                            expression = curve_list[j] + "x^" + exponent
                        else:
                            expression = expression + " + " + curve_list[j] + "x^" + exponent
                # coefficient < 0 except -1
                else:
                    if exponent == "1":
                        expression = expression + curve_list[j] + "x"
                    else:
                        expression = expression + curve_list[j] + "x^" + exponent
                        
            if (B_list[i]).find("-") == -1:
                expression = "y = " + expression + " + " + B_list[i]
            else:
                expression = "y = " + expression + B_list[i]
        expressions_list.append(display_expression(X_list[i], X_list[i+1], expression))

        i = i + 1

    return expressions_list


### class ### 
class display_expression:
	def __init__(self, x_start, x_end, expression):
		self.x_start = x_start
		self.x_end = x_end
		self.expression = expression