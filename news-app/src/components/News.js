import React, { Component } from 'react'
import NewsItem from './NewsItem';
import {api_key} from '../apikey'
console.log(api_key)


export class News extends Component {
    articles = ["abc"];
    constructor() {
        super();
        this.state = {
            articles: this.articles,
            page: 1,
            laoding: false
        }
    }
    async updateNews(){
        let url = `https://newsapi.org/v2/top-headlines?country=in&category=${this.props.category}&apiKey=${api_key}&page=1&pageSize=6`;
        let data = await fetch(url);
        console.log("after data fetch");
        let parsedData = await data.json();
        console.log("parsedData : ", parsedData);
        console.log("data : ", data);
        console.log((url));
        this.setState({
            articles: parsedData.articles,
            totalResult: parsedData.totalResult,
            pageNum: Math.ceil(this.state.totalResult / 6)
        });
    }
    componentDidMount() {
        this.updateNews();
        console.log("after functional call");
    }
    goToNext = async () => {
        console.log("welcome to gotonext");
        let url = `https://newsapi.org/v2/top-headlines?country=in&category=${this.props.category}&apiKey=${api_key}&page=${this.state.page + 1}&pageSize=6`;
        let data = await fetch(url);
        let parsedData = await data.json();
        this.setState({
            articles: parsedData.articles,
            page: this.state.page + 1,
            totalResults: parsedData.totalResults,
            pageNum: Math.ceil(this.state.totalResults / 6)
        });
    }
    goToPrev = async () => {
        console.log("welcome to gotoprev");
        let url = `https://newsapi.org/v2/top-headlines?country=in&category=${this.props.category}&apiKey=${api_key}&page=${this.state.page - 1}&pageSize=5`;
        let data = await fetch(url);
        let parsedData = await data.json();
        console.log(parsedData);
        this.setState({
            articles: parsedData.articles,
            page: this.state.page - 1,
            totalResult: parsedData.totalResults,
            pageNum: Math.ceil(this.state.totalResults / 6)
        });
    }
    render() {
        return (
            <>
                <h1 className="text-center">{this.props.category.charAt(0).toUpperCase() + this.props.category.slice(1)} News</h1>
                <div className="row">
                    {
                        this.state.articles.map((element) => {
                            return <div className="col-md-4" key={element.url}>
                                <NewsItem title={element.title ? element.title : "No title"} description={element.description ? element.description : "No description"} imgurl={element.urlToImage ? element.urlToImage : "https://feeds.abplive.com/onecms/images/uploaded-images/2021/09/09/f20316bff32a84f7981729425566435b_original.jpg?impolicy=abp_cdn&imwidth=1200&imheight=628"} url={element.url} date={element.publishedAt} />
                            </div>
                        })
                    }
                </div>
                <div className="container d-flex justify-content-between">
                    <button disabled={this.state.page <= 1} type="button" class="btn btn-dark" onClick={this.goToPrev}>Previous</button>
                    <button disabled={this.state.page >= this.state.pageNum} type="button" class="btn btn-dark" onClick={this.goToNext}>Next</button>
                </div>
            </>
        )
    }
}

export default News