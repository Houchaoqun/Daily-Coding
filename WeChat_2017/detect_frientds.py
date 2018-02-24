import itchat

# 先登录
itchat.login()

chatroomUserName = '@1234567'
friend = itchat.get_friends()[1]

r = itchat.add_member_into_chatroom(chatroomUserName, [friend])
if r['BaseResponse']['ErrMsg'] == '':
    status = r['MemberList'][0]['MemberStatus']
    itchat.delete_member_from_chatroom(chatroom['UserName'], [friend])
    return { 3: u'该好友已经将你加入黑名单。',
        4: u'该好友已经将你删除。', }.get(status,
        u'该好友仍旧与你是好友关系。')