//
//  ViewController.swift
//  EdisonRCCar
//
//  Created by Carlton Jester on 4/19/15.
//  Copyright (c) 2015 Fanzone, LLC. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    /*
    0=stop
    1=forward
    2=reverse
    3=right
    4=left
    5=forward right
    6=forward left
    7=reverse right
    8=reverse left
    */
    enum Directions: Int
    {
        case Stop = 0
        case Forward = 1
        case Reverse = 2
        case Right = 3
        case Left = 4
        case ForwardRight = 5
        case ForwardLeft = 6
        case ReverseRight = 7
        case ReverseLeft = 8
    }
    @IBOutlet weak var statusLabel: UILabel!
    
    
    
    
    @IBAction func tapGestureRecognizer(sender: UITapGestureRecognizer) {
        var location = sender.locationInView(self.view)
        var h = self.view.frame.height/3
        var w = self.view.frame.width/3
        if CGRectContainsPoint(CGRect(x: 0, y: 0, width: w, height: h), location)
        {
            //forward left
            postDirectionValue(Directions.ForwardLeft.rawValue)
            statusLabel.text = "Forward Left"
            println("Rect 1")
        }
        if CGRectContainsPoint(CGRect(x: w, y: 0, width: w, height: h), location)
        {
            //forward
            postDirectionValue(Directions.Forward.rawValue)
            statusLabel.text = "Forward"
            println("Rect 2")
        }
        if CGRectContainsPoint(CGRect(x: w*2, y: 0, width: w, height: h), location)
        {
            //forward right
            postDirectionValue(Directions.ForwardRight.rawValue)
            statusLabel.text = "Forward Right"
            println("Rect 3")
        }
        if CGRectContainsPoint(CGRect(x: 0, y: h, width: w, height: h), location)
        {
            //left
            postDirectionValue(Directions.Left.rawValue)
            statusLabel.text = "Left"
            println("Rect 4")
        }
        if CGRectContainsPoint(CGRect(x: w, y: h, width: w, height: h), location)
        {
            //stop
            postDirectionValue(Directions.Stop.rawValue)
            statusLabel.text = "Stop"
            println("Rect 5")
        }
        if CGRectContainsPoint(CGRect(x: w*2, y: h, width: w, height: h), location)
        {
            //right
            postDirectionValue(Directions.Right.rawValue)
            statusLabel.text = "Right"
            println("Rect 6")
        }
        if CGRectContainsPoint(CGRect(x: 0, y: h*2, width: w, height: h), location)
        {
            //reverse left
            postDirectionValue(Directions.ReverseLeft.rawValue)
            statusLabel.text = "Reverse Left"
            println("Rect 7")
        }
        if CGRectContainsPoint(CGRect(x: w, y: h*2, width: w, height: h), location)
        {
            //reverse
            postDirectionValue(Directions.Reverse.rawValue)
            statusLabel.text = "Reverse"
            println("Rect 8")
        }
        if CGRectContainsPoint(CGRect(x: w*2, y: h*2, width: w, height: h), location)
        {
            //reverse right
            postDirectionValue(Directions.ReverseRight.rawValue)
            statusLabel.text = "Reverse Right"
            println("Rect 9")
        }
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        postDirectionValue(0);
        //let currentValue = getData()
        
    }
    
    func postDirectionValue(directionVal:Int)
    {
        var url: NSURL = NSURL(string: "http://www.carltonjester.com/edison/RCCarControlSetter.php")!
        var request:NSMutableURLRequest = NSMutableURLRequest(URL:url)
        var bodyData = "direction="+String(directionVal)
        request.HTTPMethod = "POST"
        request.HTTPBody = bodyData.dataUsingEncoding(NSUTF8StringEncoding);
        NSURLConnection.sendAsynchronousRequest(request, queue: NSOperationQueue.mainQueue())
            {
                (response, data, error) in
                //println(response)
        }
    }
    
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    @IBAction func directionModeChange(sender: UISegmentedControl) {
        postDirectionValue(sender.selectedSegmentIndex)
    }

}

