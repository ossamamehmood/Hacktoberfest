import discord
from discord.ext import commands
import wikipedia
from stackapi import StackAPI


client = discord.Client()
@client.event
async def on_ready():
    print("Bot is online")


@client.event
async def on_message(message):
    message.content.lower()
    if message.author == client.user:
        return

    elif message.content.startswith("hello") or message.content.startswith("Hello"):
        await message.channel.send("Hello, I am Cheatbot, here to help you cheat!")

    elif message.content.startswith("cheat ping"):
        await message.channel.send(f'{round(client.latency*1000)}ms')

    elif message.content.startswith("cheat wiki"):
        try:
            term =(message.content.split())
            search=''
            link=''
            for k in term[2:]:
                search=search + k + ' '
                link=link + k + '_'
            result = wikipedia.summary(search, sentences = 3)
            embed = discord.Embed(title='Go to wikipedia',url="https://en.wikipedia.org/wiki"+link,description=result)
            await message.channel.send(embed=embed)
        except:
            await message.channel.send("could not find "+search+" on wikipedia")

    elif message.content.startswith("cheat question"):
        no_of_options=4
        question=''
        question_list=message.content.split()
        if question_list[-1].isnumeric():
            no_of_options=int(question_list[-1])
            for k in question_list[2:len(question_list)-1]:
                question=question + k + ' '
        else:
            no_of_options=4
            for k in question_list[2:len(question_list)]:
                question=question + k + ' '
        print(no_of_options)
        print(question)
        await message.channel.send(question)
        for k in range(no_of_options):
            await message.channel.send(reactions[k])

    
    elif message.content.startswith("cheat help"):
        await message.channel.send("""Commands
-------------------------------------------------------------------------------------------------------
1 : cheat wiki something to search
This command will search wiki and give a short description, along with a link to that page
2 : cheat error some error
This command will search for your error on stack overflow and give links to 3 answers
------------------------------------------------------------------------------------------------------
Examples
-------------------------------------------------------------------------------------------------------
cheat wiki data structures
cheat error SIGSEV""")

    elif message.content.startswith("cheat error"):
        message.content.lower()
        error_statement=''
        error_list =(message.content.split())
        flag=0
        if error_list[-1].isnumeric():
            no_of_links=int(error_list[-1])
            error_statement=''
            flag=1
            for k in term[2:len(error_list)-1]:
                error_statement=error_statement + k + ' '
        else:
            error_statement=''
            for k in error_list[2:len(error_list)]:
                error_statement=error_statement + k + ' '
        def solve_error(error: str, max_links: int = 3) -> [(str, str)]:
            SITE = StackAPI('stackoverflow')
            comments = SITE.fetch('search/advanced', sort = 'relevance', q = error)
            count = 0
            links = []

            for i, ans in enumerate(comments['items']):
                if ans['is_answered']:
                    count += 1
                    if count > max_links:
                        break
                    links.append((ans['title'], ans['link']))
            
            return links
        if flag==1:
            for link in solve_error(error_statement,no_of_links):
                embed = discord.Embed(title=link[0],url=link[1],description="For more clarification visit above links")
                await message.channel.send(embed=embed)
        if flag==0:
            for link in solve_error(error_statement):
                embed = discord.Embed(title=link[0],url=link[1],description="For more clarification visit above links")
                await message.channel.send(embed=embed)
        
client.run('NzI3ODA1MjMyNDM5ODg1ODI1.XvxPCQ.QoLEMQb52qvntGPqb1nDr54bjfs')
