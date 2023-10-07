import discord
from discord.ext import commands

# Create a bot instance
client = commands.Bot(command_prefix="!",intents=discord.Intents.all())

@client.event
async def on_ready():
    print(f"Logged in as {client.user.name}")

@client.command()
async def hello(ctx):
    await ctx.send("Hello!")
