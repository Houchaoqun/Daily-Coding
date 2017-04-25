#-*- encoding: utf-8 -*-
import poplib
import email, string, sys, os
from email.Header import Header
from email.Header import decode_header

popClient = poplib.POP3('pop.exmail.qq.com')
popClient.set_debuglevel(1)
popClient.user('3345947441@qq.com')
popClient.pass_('qwerty123')

numMsgs, mboxSize = popClient.stat()


# print "Number of messages ", numMsgs
# print "Mailbox size", mboxSize
# print popClient.list()

def showMessage(mail):
    if mail.is_multipart():
        for part in mail.walk():
            showmessage(part)
    else:
        type = mail.get_content_charset()
        if type == 'None':
            print mail.get_payload()
        else:
            try:
                print unicode(mail.get_payload('base64'), type)
            except:
                print mail.get_payload()

print "start..."
for id in range(numMsgs):
    hdr, message, octet = popClient.retr(id + 1)
    mail = email.message_from_string(string.join(message, '\n'))
    mail['subject'], mail.get('subject')
    mail['from'], mail.get('from')
    mail['To'], mail.get('To')
    mail['date'], mail.get('date')
    subject = email.Header.decode_header(mail['subject'])[0][0]
    subcode = email.Header.decode_header(mail['subject'])[0][1]
    FromAddr = email.Header.decode_header(mail['from'])[0][0]
    ToAddr = email.Header.decode_header(mail['To'])[0][0]
    date = email.Header.decode_header(mail['date'])[0][0]
    print '*******************************************'
    print '   ********** mail', id + 1, '****************   '
    print '\n'
    print  'Subject: ', subject
    print 'From: ', FromAddr
    print 'To: ', ToAddr
    print 'Date: ', date
    print '邮件内容:'
    showMessage(mail)
    print '\n\n'

popClient.quit()