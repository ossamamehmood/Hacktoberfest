import React, { Component } from 'react'

export class NewsItem extends Component {
    render() {
        let { title, description, articles, imgurl, url } = this.props;
        return (
            <div className="container my-3">
                <div className="card" style={{ width: "18rem" }}>
                    <img src={imgurl} className="card-img-top" alt="..." />
                    <div className="card-body">
                        <h5 className="card-title"><b>{title}</b></h5><br/>
                        <h6>{description}</h6>
                        <p className="card-text">{articles}</p>
                        <a href={url} target="_blank" rel="noreferrer" className="btn btn-primary">Detailed news</a>
                        <h6>{this.props.date}</h6>
                    </div>
                </div>
            </div>
        )
    }
}

export default NewsItem
