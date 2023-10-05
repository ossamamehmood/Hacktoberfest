import { useEffect, useState } from "react";

import {API_KEY} from './utils'
export function useData(param){
   
    const [data,setData]=useState()
    const fetchData=async()=>{
        const res=await fetch(`https://youtube.googleapis.com/youtube/v3/videos?part=snippet%2CcontentDetails%2Cstatistics&id=${param}&key=`+API_KEY)
         const data=await res.json()
         setData(data)
     }
     useEffect(()=>{
         fetchData()
     },[param])
     return data;
}
