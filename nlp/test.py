#!encoding=utf-8
import jieba
import time

jieba.load_userdict("dict.txt")
import jieba.posseg as pseg


text = '''
搜狐娱乐讯（文/耷子）美国当地时间2月4日，被誉为美国“动画奥斯卡”的第44届美国动画安妮奖，揭晓了获奖名单。年度口碑力作《疯狂动物城》成为本届安妮奖的最大赢家，横扫最佳动画长片、最佳导演、最佳剧本、最佳配音等六项大奖，离奥斯卡最佳长片奖近在咫尺。吉卜力出品的动画电影《红海龟》收获了最佳独立动画长片奖。皮克斯的《海底总动员2》颗粒无收。
　　本届安妮奖的宠儿《疯狂动物城》在去年春季登场之后，被北美评论界大为赞赏。影片的制作班底来自奥斯卡最佳动画长片《超能陆战队》。不过，相对于前者靠卖萌来赢得观众，《疯狂动物城》的故事创作其实更加用心，整个动物“乌托邦”世界都设置得充满想像力。影片的故事发生在动物居住的大都市，每种动物都可以和谐共处。初出茅庐的警官兔子朱迪发现，要和一群大动物警察一起工作需要花费更多的心力。为了证明能力，朱迪全力以赴破获一桩神秘案件，却被迫和狡猾的狐尼克搭档。随着调查的不断深入，朱迪发现，一个企图将动物城颠覆的阴谋正在逼近这个美好的社会。影片在北美影评人那里得到了98%的好评率。
　　美国动画安妮奖，由国际动画协会主办，至今已举办了43届，它的评选对象包括了美国全年发行的动画电影和电视作品。随着奥斯卡增设了最佳动画长片奖，安妮奖也越来越被视为奥斯卡动画奖项的风向标。客观而言，由于每年到年底时，全年的动画片基本都已出炉，因此水准高低和奖项走势基本已经形成，比如2007年的《料理鼠王》就在安妮奖和奥斯卡占有绝对优势。2008年的《机器人瓦力》显然有点霉运，最终败给了《功夫熊猫》。2009年口碑最好的动画片《飞屋环游记》则败给了《鬼妈妈》。2011年安妮奖得主《兰戈》最终摘取了奥斯卡最佳动画长片奖，2012年的安妮奖得主《无敌破坏王》最后在奥斯卡上输给了皮克斯的《勇敢传说》。上一届的安妮奖得主《头脑特工队》最终赢得了奥斯卡最佳长片奖。
　　第44届美国动画安妮奖电影类获奖名单：
　　最佳动画电影Best Animated Feature
　　《疯狂动物城》Zootopia
　　最佳独立动画电影Best Animated Feature – Independent
　　《红海龟》The Red Turtle
　　最佳动画特别制作Best Animated Special Production
　　《梨酒与香烟》Pear Cider and Cigarettes
　　最佳动画电影动画效果Outstanding Achievement, Animated Effects in an Animated Production
　　《海洋奇缘》Moana
　　最佳真人电影动画效果Outstanding Achievement, Animated Effects in a Live Action Production
　　《奇异博士》Dr. Strange
　　最佳动画电影角色Outstanding Achievement, Character Animation in a Feature Production
　　《久保与二弦琴》Kubo and the Two Strings
　　最佳真人电影动画角色Outstanding Achievement, Character Animation in a Live Action Production
　　《丛林之书》The Jungle Book（两项）
　　最佳动画电影角色设计Outstanding Achievement, Character Design in an Animated Feature Production
　　《疯狂动物城》Zootopia
　　最佳动画电影导演Outstanding Achievement, Directing in an Animated Feature Production
　　拜恩-霍华德、里奇-摩尔-《疯狂动物城》Zootopia
　　最佳动画电影音乐Outstanding Achievement, Music in an Animated Feature
　　《小王子》The Little Prince
　　最佳动画电影场景设计Outstanding Achievement, Production Design in an Animated Feature Production
　　《久保与二弦琴》Kubo and the Two Strings
　　最佳动画电影故事板Outstanding Achievement, Storyboarding in an Animated Feature Production
　　《疯狂动物城》Zootopia
　　最佳动画电影配音Outstanding Achievement, Voice Acting in an Animated Feature Production
　　《疯狂动物城》Zootopia
　　《海洋奇缘》Moana
　　最佳动画电影剧本Outstanding Achievement, Writing in an Animated Feature Production
　　《疯狂动物城》Zootopia
　　最佳动画电影剪辑Outstanding Achievement, Editorial in an Animated Feature Production
　　《久保与二弦琴》Kubo and the Two Strings
'''

#print ' --- '.join(jieba.cut(text))

words = pseg.cut(text)
for w in words:
    if w.flag in ['nm']:
        print w.word, w.flag
