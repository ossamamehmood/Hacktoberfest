import React from 'react';
// to ignore warning of import next line
// eslint-disable-next-line
import { Chart as ChartJS } from "chart.js/auto"; // NOTE: import this for chartjs to work
import { Line } from "react-chartjs-2";
import { Row, Col, Typography } from "antd";

const { Title } = Typography;

const LineChart = ({ coinHistory, currentPrice, coinName }) => {

  const coinPrice = [];
  const coinTimeStamp = [];

  for(let i = 0; i<coinHistory?.data?.history?.length; i+=1) { // array input to base our line chart.
    coinPrice.push(coinHistory.data.history[i].price)
    coinTimeStamp.unshift(new Date(coinHistory.data.history[i].timestamp * 1000).toLocaleDateString()); // to make the more readable.
  }
  
  const data = {
    labels: coinTimeStamp,
    datasets: [
      { 
        label: 'Price in USD',
        data: coinPrice,
        fill: false,
        backgroundColor: '#C69564',
        borderColor: '#C69564'
      }
    ]
  }

  const options = {
    scales: {
      yAxes: [
        {
          ticks: {
            beginAtZero: true
          }
        }
      ]
    }
  }

  return (
    <>
      <Row className="chart-header">
        <Title level={2} className="chart-title">
          {coinName} Price Chart
        </Title>
        <Col className="price-container">
          <Title level={5} className="price-change">
            {coinHistory?.data?.change}%
          </Title>

          <Title level={5} className="current-price">
            Current {coinName} Price: $ {currentPrice}
          </Title>
        </Col>
      </Row>

      <Line
        data={data}
        options={options}
      />
    </>
  );
}

export default LineChart