import scrapy 
from scrapy.crawler import CrawlerProcess

class quoteSpider(scrapy.Spider):
    name = 'quoteScraper'
    custom_settings = {
        # export as JSON format
        "FEED_FORMAT" : "json",
        "FEED_URI" : "scrape_data.json"
    }
    start_urls = ['https://quotes.toscrape.com/']

    def start_requests(self):
        url ="https://quotes.toscrape.com/"
        yield scrapy.Request(url=url,callback=self.parse)
    def parse(self,response):
        allQuotes = response.css('div.quote')
        for i in range(len(allQuotes)):
            quotes = allQuotes[i].css('span.text::text').extract_first()
            author = allQuotes[i].css('small.author::text').extract_first()
            tags = allQuotes[i].css('div.tags a.tag::text').extract()
            data = {'quote':quotes,'author':author,'tags':tags}
            yield data

        navigation = response.css('nav li.next>a::attr(href)').extract_first()
        if navigation:
            next_page = response.urljoin(navigation)
            # Scrapy has built in duplicate filtering which is turned on by default, now we've turned off
            yield scrapy.Request(next_page, callback=self.parse,dont_filter=True)

process = CrawlerProcess()
process.crawl(quoteSpider)
process.start()


## For step by step guide refer:
## https://medium.com/@muhammadhassanniazi85/web-scraping-in-python-using-scrapy-first-spider-24dd60016b31
