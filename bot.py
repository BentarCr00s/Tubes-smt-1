import os
import openai

openai.api_key = os.getenv("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")

response = openai.Completion.create(
  model="text-davinci-003",
  prompt="Buat lah essay tentang bot trading sebanyak 1000 kata",
  temperature=0.7,
  max_tokens=2000,
  top_p=1,
  frequency_penalty=0,
  presence_penalty=0
)